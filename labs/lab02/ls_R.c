#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

// struct dirent {
//       ino_t          d_ino;       /* Inode number */
//       off_t          d_off;       /* Not an offset; see below */
//       unsigned short d_reclen;    /* Length of this record */
//       unsigned char  d_type;      /* Type of file; not supported
//                                      by all filesystem types */
//       char           d_name[256]; /* Null-terminated filename */
//};


// d_type :  folder = 4, file = 8

void f(char *path){
    DIR *dp = opendir(path);
    // printf("%s\n", path);
    struct dirent *d = readdir(dp);
    
    while(d != NULL){
		if(strcmp(d -> d_name, ".") != 0 && strcmp(d -> d_name, "..") != 0){
    		printf("%s\n", d -> d_name);
		}
    	if(d -> d_type == 4 && strcmp(d -> d_name, ".") != 0 && strcmp(d -> d_name, "..") != 0){
    	  char temp[200];
    	  strcpy(temp, path);
    	  strcat(temp, "/");
    	  strcat(temp, d -> d_name);
    	  f(temp);
    	}
		d = readdir(dp);
    }
}

int main(){
    char buf[100];
    char* c = getcwd(buf, sizeof(buf));
    
    f(c);
    
    return 0;
}
 
 
