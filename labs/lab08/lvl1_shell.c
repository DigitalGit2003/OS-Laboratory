#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

// commands

int main(int nargs, char *args[]){
    int pid = fork();
    if(pid == 0){
        char path[100];
        strcpy(path,"/bin/");
        strcat(path,args[1]);
        int n = execl(path,args[1], NULL);
        if(n == -1){
            printf("Please enter valid command.\n");
        }
    }else if(pid > 0){
        wait(NULL);
    }
    return 0;
}