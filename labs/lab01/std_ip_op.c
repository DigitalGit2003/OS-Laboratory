#include<unistd.h>

// int x = read(fd,num,n);
// will read "n" bytes from fd = "fd" file, and will store in num

int main(){

    char num[100];

    int n = read(0, num, sizeof(num));  
    // read from fd = 0 (fd = 0 means standard input) and store in num. 
    // return -> (n) = no. of bytes passed in standard input.

    int x = write(1,num,n);
    // will print "n" bytes from "num", at fd = 1(output screen)
    return 0;
    
}

// read(kemathi read karvanu?, kya store karvanu?, ketlu read karvanu?)
// write(kya write karvanu?, kemathi write karvanu?, ketlu write karvanu?)
