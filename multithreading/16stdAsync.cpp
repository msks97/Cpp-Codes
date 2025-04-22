#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>
#include <future>


typedef long int ull;

using namespace std;

ull findOdd(ull start, ull end)
{
    ull oddSum =0;
    for(ull i = start; i<=end; i++)
    {
        if (i & 1)
        {
            oddSum+=i;
        }
    }
    return oddSum;
}



int main()
{

    ull start = 0 , end = 1900000000;

    cout<<"\nThread created is policy is std::launch async!!"<<endl;
    future<ull> oddSum = async(launch::async, findOdd, start, end);
    //in launch::async thread is created of main and when function is called separately
    //in launch::deffered thread only main thread is there no additinal thread is created.

    
    cout<<"waiting for Result!!"<<endl;

    cout<<"OddSum:"<<oddSum.get()<<endl; // will wait for the oddsum to return from function which started from line 33

    cout<<"completed!!"<<endl;

    //t1.join();
    return 0;
}