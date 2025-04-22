#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1, m2;

void T1()
{
    m1.lock();
    m2.lock();
    cout<<"\nCritical section of T1"<<endl;
    m1.unlock();
    m2.unlock();
}

void T2()
{
    m2.lock();
    m1.lock();
    cout<<"\nCritical section of T2"<<endl;
    m2.unlock();
    m1.unlock();
}

/// here in the above two function lets deadlock may arise as in one function m1 is called 
//and then in other function m2 is called then m1. 
//This will cause the functions to wait indefinitely for each other.

//So never change the order of locks.
//to avoid deadlocks change t2 fumnction's order to m1.lock() then m2.lock(). similarly for unlock.

int main()
{
    thread t1(T1);
    thread t2(T2);

    t1.join();
    t2.join();

    return 0;
}