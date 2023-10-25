// 5. Write a program to achieve following:    
//     - Child process should open a file with the contents to be sorted, pass the contents to parent process.
//     - Parent process should sort the contents of the file and display.


////////////////////////////////////////////////////////////////////////
//////////////////     MY CODE     /////////////////////////////////////
////////////////////////////////////////////////////////////////////////

/*
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int nargs, char *args[]){
    // create pipe
    int pipefd[2];
    int p = pipe(pipefd);


    int pid = fork();
    if(pid == 0){
        int fd = open(args[1], O_RDONLY);
        char buff[10000];
        read(fd,buff,sizeof(buff));
        write(pipefd[1],buff,sizeof(buff));
    }else if(pid > 0){
        
    }

    return 0;
}
*/

////////////////////////////////////////////////////////////////////////
//////////////////     DHRUVIN'S CODE     //////////////////////////////
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main () {
    int pipefd[2];
    pipe(pipefd);
    int pid = fork();
    if (pid > 0)  //parent
    {
        wait(NULL);
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        execl("/bin/sort", "sort", NULL);
    }
    else if (pid == 0)  //child
    {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        char buff[1024];
        int fileFd = open("Test.txt", O_RDONLY);
        ssize_t bytesRead = read(fileFd, buff, sizeof(buff));
        write(1, buff, bytesRead);
    }
    return 0;
}
