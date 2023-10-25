#include<unistd.h>
#include<stdio.h>

int main(){
    char buf[100];
    char* c = getcwd(buf, sizeof(buf));
    printf("%s\n", c);
    int n = write(1, c, sizeof(c)); // giving wrong answer due to buffer
    return 0;
}
 
/*    ls.c
 
 
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>


int main(){
    char buf[100];
    char* c = getcwd(buf, sizeof(buf));
    
    DIR *dp = opendir(c);
    
    struct dirent *d = readdir(dp);
    
    while(d != NULL){
    	printf("%s\n", d -> d_name);
	d = readdir(dp);
    }
    
    return 0;
 }
 
 */
