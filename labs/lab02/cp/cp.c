#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int nargs, char *args[]){
    int source_fd = open(args[1], O_RDONLY);
	  
    char bf[100];
    int number_of_bytes_read = read(source_fd, bf, sizeof(bf));
    
    int destination_fd = open(args[2], O_WRONLY | O_CREAT);
    int bytes_written = write(destination_fd, bf, number_of_bytes_read);
    
    return 0;
}


