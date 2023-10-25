#include<pthread.h>
#include<stdio.h>

struct s{
   int x,y;
};

void * addition(void *vp){
   struct s *sptr = (struct s*)vp;
   printf("x+y = %d\n", sptr->x + sptr->y);
   return NULL;
}
void * subtract(void *vp){
   struct s *sptr = (struct s*)vp;
   printf("x-y = %d\n", sptr->x - sptr->y);
   return NULL;
}
void * multiply(void *vp){
   struct s *sptr = (struct s*)vp;
   printf("x*y = %d\n", sptr->x * sptr->y);
   return NULL;
}
void * division(void *vp){
   struct s *sptr = (struct s*)vp;
   printf("x/y = %d\n", sptr->x / sptr->y);
   return NULL;
}

int main(){
   pthread_t tadd, tsub, tmul, tdiv;
   
   struct s obj;
   obj.x = 20;
   obj.y = 10;
   
   struct s *ptr = &obj;
   printf("x = %d, y = %d\n",obj.x,obj.y); 
   int add = pthread_create(&tadd, NULL, addition((void*)ptr), NULL);
   int sub = pthread_create(&tsub, NULL, subtract((void*)ptr), NULL);
   int mul = pthread_create(&tmul, NULL, multiply((void*)ptr), NULL);
   int div = pthread_create(&tdiv, NULL, division((void*)ptr), NULL);

   pthread_join(tadd,NULL);
   pthread_join(tsub,NULL);
   pthread_join(tmul,NULL);
   pthread_join(tdiv,NULL);
   
   return 0;
}
