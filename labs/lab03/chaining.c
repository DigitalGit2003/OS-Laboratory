#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
    int n;
    scanf("%d", &n);
    
    int pid = fork();
    for(int i = 0; i < n; i++){
    	if(pid == 0){
    	   printf("Parent %d, Child %d\n", getppid(), getpid());
    	   pid = fork();
    	}
    	wait(NULL);
    }
     
    return 0;
}
