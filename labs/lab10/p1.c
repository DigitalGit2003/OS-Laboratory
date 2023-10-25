// 1. WAP to Implement solution for readers have priority problem.

#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int readcount;
int count = 0;
sem_t x, wsem;

void *reader()
{
    while (1)
    {
        sem_wait(&x);
        readcount++;
        if (readcount == 1)
        {
            sem_wait(&wsem);
        }
        sem_post(&x);

        // READUNIT();
        count--;
        
        printf("Reader read ####: %d count : %d\n", readcount, count);
        sleep(1);

        sem_wait(&x);
        readcount--;
        if (readcount == 0)
        {
            sem_post(&wsem);
        }
        sem_post(&x);
        
    }
}

void *writer()
{
    while (1)
    {
        sem_wait(&wsem);
        // WRITEUNIT();
        count++;
        printf("Writer write : %d , count : %d\n", readcount, count);
        sleep(1);
        sem_post(&wsem);
    }
}

int main()
{
    readcount = 0;
    sem_init(&x, 0, 1);
    sem_init(&wsem, 0, 1);
    pthread_t r[5], w[5];

    for(int i = 0; i < 5; i++){
        pthread_create(&w[i], NULL, writer, NULL);
        pthread_create(&r[i], NULL, reader, NULL);
    }


    for(int i = 0; i < 1; i++){
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }
     
    return 0;
}