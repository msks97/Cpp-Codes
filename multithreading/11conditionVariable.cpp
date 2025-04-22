#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cv;
long balance = 0 ;

void addMoney(int money)
{
    lock_guard<mutex> lg(m);
    balance += money;
    cout<<"Amount available is: "<<balance<<endl;
    cv.notify_one();
}

void Withdraw(int money)
{
    unique_lock<mutex> ul(m);
    cv.wait(ul, [](){return (balance<=0 ? false : true);}); //wait and relase until the condition is satisfied
    if(balance>=money)
    {
        balance-=money;
        cout<<"Amount deducted: "<<money<<endl;
    }
    else
    {
        cout<<"Amount cant be deducted as balance is less than "<<money<<endl;
    }
    cout<<"Current balance is:"<<balance<< endl;
}

int main()
{
    thread t1(Withdraw, 5000);
    thread t2(addMoney, 1000);

    t1.join();
    t2.join();

    return 0;
}