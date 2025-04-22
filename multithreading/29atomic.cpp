//atomic
#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

atomic<int> x=0;
//int x = 0;
mutex m;

void addMoney(int num)
{
    //m.lock(); //not required with atomic
    for(int i=0; i<100000; i++)
    {
        //cout<<"Num :"<<num<<" : "<<x<<endl;
        ++x;
    }
    //m.unlock(); //not reuqired with atomic
        
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