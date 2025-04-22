#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int amount = 0;
timed_mutex m;

void increment(int x)
{
    //if(m.try_lock_for(3s)) chrono::seconds(3)
    if(m.try_lock_until(chrono::steady_clock::now() + 2s))
    {
        amount++;
        this_thread::sleep_for(1s);
        cout<<"Thread "<<x<<" Entered "<<endl;
        m.unlock();
    }
    else
    {
        cout<<"Thread "<<x<<" couldn't enter "<<endl;
    }
}

int main()
{
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    cout<<amount<<endl;
    return 0;

}