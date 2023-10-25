#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
   // printf("Hello from parent");
    int p_id = fork();
    //fork();
    //fork();
    //fork();
    //fork();
    
    if(p_id == 0){
        printf("Hello from child\n"); 
        printf("child_id : %d\n", getpid());
        printf("parent_id : %d\n", p_id);
        wait(NULL);
    }else if(p_id > 0){
        printf("Hello from parent\n"); 
    	printf("child_id : %d\n", getpid());
        printf("parent_id : %d\n", getppid());
    }else{
        printf("it's error");
    }
    
    return 0;
}   
