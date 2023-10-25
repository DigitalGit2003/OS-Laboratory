#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>


int main(){
    char *p = "/proc"; 
    DIR *dp = opendir(p);
    struct dirent *dr = readdir(dp);
     
    while(dr != NULL){
        char *name = dr -> d_name;
    
        int isNum = 1;
        while(*name != 0){
            if(*name < '0' || *name > '9'){
                isNum = 0;
                break;
            }
            name++;
        }


        if(isNum){
            char path[30] = "/proc/";
            strcat(path, dr -> d_name);
            strcat(path, "/stat");
            // printf("%s\n", path);
            FILE* fp = fopen(path, "r");
            // int display;
            // while(1){
            //     display = fgetc(fp);
            //     if(feof(fp)){
            //         break;
            //     }
            //     printf("%c", display);
            // }
            fscanf(fp, )
            fclose(fp);
        } 
        
        dr = readdir(dp);
    }
    
    return 0;
}







