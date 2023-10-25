#include<pthread.h>
#include<stdio.h>

void * fun1(void *vp){
   printf("Hello world from fun1\n");
   return NULL;
}

void * fun2(void *vp){
   printf("Hello world from fun2\n");
   return NULL;
}

int main(){
   pthread_t t1, t2;
   
   int t1_id = pthread_create(&t1, NULL, fun1, NULL);
   int t2_id = pthread_create(&t2, NULL, fun2, NULL);
   
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   
   return 0;
}
