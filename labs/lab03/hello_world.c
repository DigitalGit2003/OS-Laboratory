#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>


int main(){
    printf("Hello\n");
    fork();
    fork();
    printf("World");
    return 0;
}
