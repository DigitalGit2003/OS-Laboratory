#include<unistd.h>
#include<stdio.h>

// int x = write(1,num,n);
// will print "n" bytes from "num", at fd = 1(output screen)

int main(){

    char *str = "Hello gautam\n";
    int num = write(1,str, sizeof("Hello gautam\n"));
    // write at fd = 1 (fd = 1 means standard output[output screen])
    // return -> (num) = no. of bytes written.
    // sizeof(str) will not work, because str is a pointer, and size of pointer is of 8 bytes
    // so it will only print first 8 characters.


    printf("%d\n", num); // will print 14 = sizeof("Hello gautam\n") 
    return 0;
    
}

