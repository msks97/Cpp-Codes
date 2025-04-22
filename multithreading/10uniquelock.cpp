#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m;
int buffer = 0;

void task(int thread, int i)
{
    //unique_lock<mutex> lock(m); //Automatically call lock on mutex m.

    unique_lock<mutex> lock(m, defer_lock);// Does not call lock on mutex m, because used defer_lock
	lock.lock();  // But then we will have to explicitly tell to lock when ever we want to lock mutex m.

    for(int j=0; j<i; j++)
    {
        buffer++;
        cout<<thread<<" : " <<buffer<<endl;
    }
    // lock.unlock(); is not needed as it will be unlocked in destructor of unique_lock.

}

int main()
{
    thread t1(task, 1, 10);
    thread t2(task, 2, 10);

    t1.join();
    t2.join();

    return 0;

}