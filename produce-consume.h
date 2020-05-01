#ifndef __USER_H__
#define __USER_H__
#include "LockedQueue.h"
#include "thread.h"

using namespace std;
class producer :public thread
{
public:
    producer(TaskQueue &taskqueue);
    void run();
private:
    TaskQueue &taskqueue;
};



class consumer:public thread
{
public: 
    consumer(TaskQueue &taskqueue);
    void run();
private:
    TaskQueue &taskqueue;
};

#endif