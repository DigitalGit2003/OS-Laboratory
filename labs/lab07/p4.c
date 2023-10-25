// 4. Write a program to implement ls | sort functionality.

////////////////////////////////////////////////////////////////////////
//////////////////     MY CODE     /////////////////////////////////////
////////////////////////////////////////////////////////////////////////
/*
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
    // create pipe
    int pipefd[2];
    int p = pipe(pipefd);


    int pid = fork();
    char ls_data[1000];
    if(pid == 0){
        int new_fd = dup2(pipefd[1], 1);
        execl("/bin/ls", "ls", NULL);
    }else if(pid > 0){
        read(pipefd[0], ls_data, sizeof(ls_data));
        printf("%s\n", ls_data);
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
    if(pid > 0) //parent
    { 
        wait(NULL);
        close(pipefd[1]);
        // our pipe is outputing to stdout
        // now to read from there we need to take data from stdin
        // so stdout is outputing and stin is receiving
        dup2(pipefd[0], 0);
        // now this function will have listing and now it will sort
        execl("/bin/sort", "sort", NULL);
    }
    else if (pid == 0)  //child
    {
        // we need to have output in our write head
        // and not in stdout
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        execl("/bin/ls", "ls", NULL);
    }
    return 0;
}