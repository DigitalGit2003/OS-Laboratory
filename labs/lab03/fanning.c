#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
    int n;
    scanf("%d", &n);
    int pid;
    for(int i = 0; i < n; i++){
        pid = fork();
        if(pid == 0){
            printf("Parent process ID for %d is %d\n", i+1, getppid());
            printf("Child process ID for %d is %d\n\n", i+1, getpid());
            break;
        }
    }    
    return 0;
}
