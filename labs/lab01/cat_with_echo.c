#include<unistd.h>

int main(){
    while(1){
       char s[100];
       int n = read(0, s, sizeof(s));
       write(1,s,n);
    }
    return 0;
}    	
