#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define philo 5
pthread_mutex_t chopstick[philo];

void *fnc(void *param)
{
    int i,iter=10;
    int n = *(int *)param;
    for(i = 0; i <iter;++i)
    {
        sleep(1);
        pthread_mutex_lock(&chopstick[n]);
        pthread_mutex_lock(&chopstick[(n + 1) % philo]);
        printf("\nBegin eating: %d with forks %d and %d",n,n,(n + 1) % philo);
        sleep(2);
        printf("\nFinish eating %d", n);
        pthread_mutex_unlock(&chopstick[n]);
        pthread_mutex_unlock(&chopstick[(n + 1) % philo]);
        printf("\nThinking:%d",n);        
    }
}

int main()
{
    int i , res;
    pthread_t th[philo];
    //void *fnc(void *);
    for(i = 0; i < philo ;++i)
        pthread_mutex_init(&chopstick[i],NULL);

    for (i=0; i < philo ; ++i)
    {
        int *arg = malloc (sizeof(int*));
        *arg = i;
        pthread_create(&th[i], NULL, fnc, arg);
    }
    for (i = 0; i < philo ; ++i)
    {
        pthread_join(th[i], NULL);
    }
}

