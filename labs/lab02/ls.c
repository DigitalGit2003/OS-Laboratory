#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>


// struct dirent {
//       ino_t          d_ino;       /* Inode number */
//       off_t          d_off;       /* Not an offset; see below */
//       unsigned short d_reclen;    /* Length of this record */
//       unsigned char  d_type;      /* Type of file; not supported
//                                      by all filesystem types */
//       char           d_name[256]; /* Null-terminated filename */
//};



int main(){
    char buf[100];
    char* c = getcwd(buf, sizeof(buf));
    
    DIR *dp = opendir(c);
    
    struct dirent *d = readdir(dp);
    
    while(d != NULL){
    	printf("%s ", d -> d_name);
    	printf("%d\n", d -> d_type);  // folder = 4, file = 8
	    d = readdir(dp);
    }
    
    return 0;
 }
