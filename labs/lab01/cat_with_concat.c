#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int main(int nargs, char* args[]){
    for(int i = 1; i < nargs; i++){
        int fd = open(args[i], O_RDONLY);
        char buff[1000];
        int n = read(fd,buff,sizeof(buff));
        write(1, buff, n); 
        close(fd);
    }
    return 0;    
}
