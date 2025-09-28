#include <pthread.h>

#include "headers/interface.h"
#include "headers/processor.h"

void* processorThreadFunc(void* args)
{
    processorStart();
    return NULL;
}

int main()
{
    pthread_t processorThread;
    pthread_create(&processorThread, NULL, processorThreadFunc, NULL);
    interfaceStart();
    pthread_join(processorThread, NULL);
    return 0;
}
