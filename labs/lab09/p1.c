// 1. Demonstrate use of semaphores to manage global variable count.


#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int count = 0;    // count is shared resource
sem_t s1;         // semaphore s1 is used to achieve synchronization.

void* fun(void *vp){
    sem_wait(&s1);
    count++;
    printf("Count : %d\n", count);
    sem_post(&s1);
    return NULL;
}

int main(){
    sem_init(&s1, 0, 1);

    pthread_t t[5];
    for(int i = 0; i < 5; i++){
        pthread_create(&t[i], NULL, fun, NULL);
    }
    for(int i = 0; i < 5; i++){
        pthread_join(t[i], NULL);
    }

    return 0;
}