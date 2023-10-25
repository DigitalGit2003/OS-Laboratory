#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){

    int curr_fd = open("test.txt", O_RDONLY);
    int new_fd = dup(curr_fd);
    int new_fd2 = dup2(curr_fd,5);

    printf("old : %d, new : %d, new2 : %d\n", curr_fd, new_fd, new_fd2);

    return 0;
}