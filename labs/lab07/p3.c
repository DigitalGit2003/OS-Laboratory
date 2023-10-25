// 3. Write a program to create a child process that should run pwd command and the parent process should run ls command.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){

    int pid = fork();

    if(pid == 0){
        execl("/bin/pwd","pwd", NULL);
    }else if(pid > 0){
        // wait(0);
        execl("/bin/ls", "ls", "-l", NULL);
    }

    return 0;
}