// 1. Create a blank file: “Test.txt”.
//     Write a program to achieve following:
//     - Print “Hello” message on stdout.
//     - Use dup2 in such a way that file behaves as stdout.
//     - Print “Hello” again to ensure that this time the message goes to file, not to the stdout.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){

    printf("hello_world \n");
    int curr_fd = open("test.txt", O_RDONLY | O_WRONLY);
    int new_fd = dup2(curr_fd,1);
    printf("hello");

    return 0;
}