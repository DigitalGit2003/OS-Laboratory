#include<pthread.h>
#include<stdio.h>

void * fun1(void *vp){
   printf("%s\n",(char*)vp);
   printf("Hello world from fun1\n");
   return NULL;
}

int main(){
   pthread_t t1;
   
   char* str = "str pointer";
   int t1_id = pthread_create(&t1, NULL, fun1((void*)str), NULL);

   pthread_join(t1,NULL);
   
   return 0;
}
