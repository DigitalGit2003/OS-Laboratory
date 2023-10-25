// 3. WAP to Implement solution for finite buffer producer consumer problem.

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s, n, e;
int buffer[10];
int it = 0;


void *producer(void *vp)
{
    while (1)
    {
        int val = 1000;
        sem_wait(&e);
        sem_wait(&s);

        buffer[it] = val;
        it++;
        printf("Item inserted : %d\n", val);
        // for(int i = 0; i < 5; i++) printf("%d       ", buffer[i]);
        // printf("\n");
        sleep(1);

        sem_post(&s);
        sem_post(&n);
    }
    return NULL;
}

void *consumer(void *vp)
{
    while (1)
    {
        sem_wait(&n);
        sem_wait(&s);

        it--;
        int consumed_item = buffer[it];
        buffer[it] = -1;
        printf("Consumed item : %d\n", consumed_item);
        // for(int i = 0; i < 5; i++) printf("%d     ", buffer[i]);
        // printf("\n");
        sleep(1);

        sem_post(&s);
        sem_post(&e);
    }
    return NULL;
}

int main()
{
    for(int i =0 ; i < 10; i++) buffer[i] = -1;
    int size = 5;
    sem_init(&s, 0, 1);
    sem_init(&n, 0, 0);
    sem_init(&e, 0, size);

    pthread_t p, c;

    // for(int i = 0; i < 3; i++){
        pthread_create(&p, NULL, producer, NULL);
    // }
    pthread_create(&c, NULL, consumer, NULL);

    // for(int i = 0; i < 3; i++){
        pthread_join(p, NULL);
    // }
    pthread_join(c, NULL);
    
    
    return 0;
}