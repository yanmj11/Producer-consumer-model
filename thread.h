#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

class thread
{
public:
    thread();
    virtual ~thread();

    void start();
    void join();
    
private:
    static void * worker(void* args);
    virtual void run()=0; 
    pthread_t _pid;
    bool stop;
};
#endif