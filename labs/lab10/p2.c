// 2. WAP to Implement solution for writers have priority problem.

#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int readcount, writecount;
sem_t x, y, z, wsem, rsem;

void reader()
{
    while (1)
    {
        sem_wait(&z);
            sem_wait(&rsem);
                sem_wait(&x);
                readcount++;
                if (readcount == 1)
                    sem_wait(&wsem);

                sem_post(&x);
            sem_post(&rsem);
        sem_post(&z);

        // READUNIT();

        sem_wait(&x);
            readcount--;
            if (readcount == 0)
                sem_post(&wsem);
        sem_post(&x);
    }
}

void writer()
{
    while (1)
    {
        sem_wait(&y);
            writecount++;
            if (writecount == 1)
                sem_wait(&rsem);
        sem_post(&y);
        
        sem_wait(&wsem);
        // WRITEUNIT();
        sem_post(&wsem);

        sem_wait(&y);
            writecount--;
            if (writecount == 0)
                sem_post(&rsem);
        sem_post(&y);
    }
}

int main()
{
    sem_init(&x, 0, 1);
    sem_init(&y, 0, 1);
    sem_init(&z, 0, 1);
    sem_init(&wsem, 0, 1);
    sem_init(&rsem, 0, 1);
    
    readcount = writecount = 0;

    return 0;
}