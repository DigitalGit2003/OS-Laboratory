#include<pthread.h>
#include<stdio.h>

struct s{
   int x,y;
};

void * fun1(void *vp){
   struct s *sptr = (struct s*)vp;
   printf("x = %d, y = %d\n", sptr->x, sptr->y);
   printf("Hello world from fun1\n");
   return NULL;
}

int main(){
   pthread_t t1;
   
   struct s obj;
   obj.x = 10;
   obj.y = 20;
   
   int t1_id = pthread_create(&t1, NULL, fun1((void*)&obj), NULL);

   pthread_join(t1,NULL);
   
   return 0;
}
