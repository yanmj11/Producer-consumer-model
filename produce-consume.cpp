#include "produce-consume.h"
#include<iostream>
using namespace std;

producer::producer(TaskQueue &q):taskqueue(q){}

void producer::run()
{
    int count=10;

    while(count--)
    {
        int num=rand()%100;
        taskqueue.push(num);
        cout << "生产: " << num << endl;
    }
}

consumer::consumer(TaskQueue &q):taskqueue(q){}

void consumer::run()
{
    int count=10;

    while(count--)
    {
        int num=taskqueue.pop();
        cout << "消费:" << num << endl;
    }
}