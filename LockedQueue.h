#ifndef __TASK_H__
#define __TASK_H__

#include <stdlib.h>
#include <queue>
#include <pthread.h>

using namespace std;

//任务队列--缓冲区
class TaskQueue
{
public:
    TaskQueue(size_t _size);
    ~TaskQueue();

    void push(int item);
    int pop();

    bool full();
    bool empty();

private:
    size_t size;
    queue<int> taskqueue;
    pthread_mutex_t mutex;
    pthread_cond_t _full;
    pthread_cond_t _empty;

};

#endif