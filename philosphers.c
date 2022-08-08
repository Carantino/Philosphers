#include <unistd.h>
#include <stdio.h>
#include <pthread.h>



void *fnc(void *varg)
{
    int i = 100;
    while(i < 200)
    {
        printf("%d\n",i);
        sleep(1);
        i++; 
    }
}

void *fnc2(void *varg)
{
    int i = 0;

    while(i < 100)
    {
        printf("%d\n", i);
        sleep(1);
        i++; 
    }
}


int main(int ac, char **av)
{
    pthread_t th;
    pthread_t th2;

    pthread_create(&th2,NULL,fnc2,NULL);
    pthread_create(&th,NULL,fnc,NULL);
    pthread_join(th,NULL);
    pthread_join(th2,NULL);    
    
}