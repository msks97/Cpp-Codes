#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;
int buffer = 0 ;

void task(int thread, int i)
{
    lock_guard<mutex> lock(m);
    for(int j=0; j<i; j++)
    {
        buffer++;
        cout<<thread<<" : " <<buffer<<endl;
    }

}


int main()
{
    thread t1(task, 1, 10);
    thread t2(task, 2, 10);

    t1.join();
    t2.join();

    return 0;

}