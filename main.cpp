#include "produce-consume.h"
#include "LockedQueue.h"
#include "thread.h"

int main()
{
    TaskQueue *taskqueue= new TaskQueue(20);
    thread *p1= new producer(*taskqueue);
    thread *p2= new producer(*taskqueue);
    thread *c1= new consumer(*taskqueue);
    thread *c2= new consumer(*taskqueue);

    p1->start();
    p2->start();
    c1->start();
    c2->start();
    p1->join();
    p2->join();
    c1->join();
    c2->join();

    delete p1;
    delete p2;
    delete c1;
    delete c2;
    delete taskqueue;
}