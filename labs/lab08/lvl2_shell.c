#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

// commands with options

int main(int nargs, char *args[]){
    int pid = fork();
    // printf("hello\n");

    if(pid == 0){
        // storing options
        if(nargs == 1){
            return 0;
        }
        char* options[100] = {NULL};
        options[0] = __FILE__;
        for(int i = 2; i < nargs; i++){
            options[i-1] = args[i];
        }

        // implementation of commands with options
        char path[100];
        strcpy(path,"/bin/");
        strcat(path,args[1]);
        int n = execv(path,options);
        if(n == -1){
            printf("Please enter valid command.\n");
        }
    }else if(pid > 0){
        wait(NULL);
        // execl("/bin/cat", "cat", NULL);
    }
    
    return 0;
}
