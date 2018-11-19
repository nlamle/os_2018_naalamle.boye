#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* run_command(void *num){
    printf("running thread %s...\n", (char*)num);
    return 0;
}


int parallel(){

    
    // for(size_t i = 0; i < num_items; i++)
    // {
    //     char t_name = 
    //     pthread_create(pthread_t )
    // }

    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, run_command, "1");
    pthread_create(&t2, NULL, run_command, "2");
    pthread_create(&t3, NULL, run_command, "3");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);


    return 0;
}

int main(int argc, char const *argv[])
{
    parallel();
    return 0;
}
