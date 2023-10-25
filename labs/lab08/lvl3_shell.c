// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include <sys/wait.h>

// // support of pipe

// int main(int nargs, char *args[]){
//     int pid = fork();
//     // printf("hello\n");

//     if(pid == 0){
//         // storing options
//         if(nargs == 1){
//             return 0;
//         }
//         char* options[100] = {NULL};
//         options[0] = __FILE__;
//         for(int i = 2; i < nargs; i++){
//             options[i-1] = args[i];
//         }

//         // implementation of commands with options
//         char path[100];
//         strcpy(path,"/bin/");
//         strcat(path,args[1]);
//         int n = execv(path,options);
//         if(n == -1){
//             printf("Please enter valid command.\n");
//         }
//     }else if(pid > 0){
//         wait(NULL);
//         // execl("/bin/cat", "cat", NULL);
//     }

//     return 0;
// }

// FULL CODE :

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

// Function to tokenize input command
int tokenizeInput(char *input, char *tokens[])
{
    int tokenCount = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL)
    {
        tokens[tokenCount++] = token;
        token = strtok(NULL, " \t\n");
    }

    tokens[tokenCount] = NULL; // Null-terminate the array
    return tokenCount;
}

void executeCommand(char *tokens[])
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // Child process
        execvp(tokens[0], tokens);
        perror("Error");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        // Parent process
        wait(NULL);
    }
    else
    {
        perror("Fork failed");
    }
}

void executePipedCommands(char *command1, char *command2)
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        printf("error in pipe\n");
        exit(0);
    }
    int pid1 = fork();
    if (pid1 < 0)
    {
        printf("Fork failed\n");
        exit(0);
    }
    else if (pid1 == 0)
    {
        // First child process (command1)
        close(pipefd[0]);               // Close read end of the pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the pipe
        close(pipefd[1]);               // Close the write end of the pipe

        char c_path[] = "/bin/";
        strcat(c_path, command1);
        execl(c_ path, command1, NULL); // Execute the first command
        perror("execl command1");
        exit(EXIT_FAILURE);
    }
    else
    {
        int pid2 = fork();
        if (pid2 < 0)
        {
            printf("Fork failed\n");
            exit(0);
        }
        else if (pid2 == 0)
        {
            // Second child process (command2)
            close(pipefd[1]);              // Close write end of the pipe
            dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to the pipe
            close(pipefd[0]);              // Close read end of the pipe

            char c_path[] = "/bin/";
            strcat(c_path, command2);
            execl(c_path, command2, NULL); // Execute the first command
            perror("execl command2");
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            close(pipefd[0]); // Close both ends of the pipe in the parent
            close(pipefd[1]);

            waitpid(pid1, NULL, 0); // Wait for the first child
            waitpid(pid2, NULL, 0); // Wait for the second child
        }
    }
}

int main()
{
    char input[MAX_INPUT_SIZE];
    char *history[MAX_INPUT_SIZE];
    int historyCount = 0;

    while (1)
    {
        printf("DaxShell> ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) > 0)
        {
            // Save command in history
            history[historyCount++] = strdup(input);

            // Tokenize input
            char *tokens[MAX_ARGS];
            int tokenCount = tokenizeInput(input, tokens);

            // Check for special characters like pipes
            int isPiped = 0;
            for (int i = 0; i < tokenCount; i++)
            {
                if (strcmp(tokens[i], "|") == 0)
                {
                    isPiped = 1;
                    tokens[i] = NULL;

                    executePipedCommands(tokens[0], tokens[i + 1]);
                    break;
                }
            }

            // Check for built-in commands
            if (strcmp(tokens[0], "history") == 0)
            {
                for (int i = 0; i < historyCount; i++)
                {
                    printf("%d: %s\n", i + 1, history[i]);
                }
            }
            else if (strcmp(tokens[0], "exit") == 0)
            {
                exit(0);
            }
            else
            {
                // Execute external commands
                if (!isPiped)
                {
                    executeCommand(tokens);
                }
            }
        }
    }

    return 0;
}