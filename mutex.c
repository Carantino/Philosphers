#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mut[1];

void *fnc(void * arg)
{
    pthread_mutex_lock(&mut[(int)arg]);
    printf("Child");
    //pthread_mutex_unlock(&mut[(int)arg]);
}


int main()
{
    pthread_t th;
    pthread_t th2;
    pthread_mutex_init(&mut[0],NULL);
    pthread_mutex_init(&mut[1],NULL);
    printf("main");
    int i = 0;
    void *x = 1;
    pthread_create(&th,NULL,fnc, x);
    //xx = 0;
    pthread_create(&th2,NULL,fnc,x);
    pthread_join(th,NULL);
    return(0);
}