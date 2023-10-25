// 2. Write a program to execute ls command using execl.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){

    printf("Before ls : \n");

    execl("/bin/ls", "ls", "-l", NULL);
    // execl("/bin/pwd","pwd", NULL);

    // control will not comeback here.
    printf("After ls : \n");

    return 0;
}