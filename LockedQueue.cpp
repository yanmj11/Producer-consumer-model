#include "LockedQueue.h"

TaskQueue::TaskQueue(size_t _size)
{
    size=_size;
    pthread_cond_init(&_full,NULL);
    pthread_cond_init(&_empty,NULL);
    pthread_mutex_init(&mutex,NULL);
}

TaskQueue::~TaskQueue()
{
    pthread_cond_destroy(&_full);
    pthread_cond_destroy(&_empty);
    pthread_mutex_destroy(&mutex);
}

void TaskQueue::push(int item)
{
    //确保各线程对缓冲区的访问是互斥的
    pthread_mutex_lock(&mutex);
    while(full())
    {
        pthread_cond_wait(&_full,&mutex);
    }
    taskqueue.push(item);
    pthread_cond_signal(&_empty);
    pthread_mutex_unlock(&mutex);
}

int TaskQueue::pop()
{
    pthread_mutex_lock(&mutex);
    while(empty())
    {
        pthread_cond_wait(&_empty,&mutex);
    }
    int item = taskqueue.front();
    taskqueue.pop();
    pthread_cond_signal(&_full);
    pthread_mutex_unlock(&mutex);

    return item;
}

bool TaskQueue::full()
{
    return taskqueue.size()==size;
}

bool TaskQueue::empty()
{
    return taskqueue.empty();
}
