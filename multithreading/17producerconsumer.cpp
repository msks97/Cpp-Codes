#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <deque>

using namespace std;

mutex m;
condition_variable cv;
deque<int> buffer;
int maxBuffer = 50, i =1;


void producer(int val)
{
    while(i<=val)
    {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [](){return (buffer.size() < maxBuffer ? true : false);});
        buffer.push_back(i);
        cout << "Produced : "<<i<<endl;
        i++;
        cv.notify_one();
    }
    
}

void consumer()
{
    while (true)
    {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [](){return (buffer.size() > 0 ? true : false);});
        int val = buffer.front();
        buffer.pop_front();
        cout<<"Consumed : "<<val<<endl;
        cv.notify_one();
    }
}


int main()
{

    thread t1(producer , 100);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;

}