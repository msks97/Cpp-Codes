//Mutex: Mutual Exclusion

//RACE CONDITION:
//0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
//1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

//MUTEX:
//0. Mutex is used to avoid race condition.
//1. We use lock() , unlock() on mutex to avoid race condition.

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int x=0;
mutex m;

void addMoney(int num)
{
    m.lock();
    for(int i=0; i<10; i++)
    {
        cout<<"Num :"<<num<<" : "<<x<<endl;
        ++x;
    }
    m.unlock(); 
        
}

int main()
{
    thread t1(addMoney,1);
    thread t2(addMoney,2);

    t1.join();
    t2.join();

    cout<<x<<endl;
    return 0;
}