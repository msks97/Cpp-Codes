#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int x=0;
mutex m;

void addMoney(int num)
{
    for(int i=0; i<1000000; i++)
    {
        if(m.try_lock())
        {
            //cout<<"Num :"<<num<<" : "<<x<<endl;
            ++x;
            m.unlock();
        }
    }     
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