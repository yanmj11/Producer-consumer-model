#include "thread.h"

thread::thread(){}

thread::~thread(){}

void thread::start()
{
    pthread_create(&_pid,NULL,worker,this);
    stop=false;
}

void thread::join()
{
    if(!stop)
    {
        pthread_join(_pid,NULL);
        stop=true;
    }
}

void* thread::worker(void*args)
{
    thread* t = (thread*)(args);
    if(t)
    {
        t->run();
    }
    return NULL;
}