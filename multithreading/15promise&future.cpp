#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>
#include <future>


typedef long int ull;

using namespace std;

void findOdd(promise<ull>& oddSumPromise, ull start, ull end)
{
    ull oddSum =0;
    for(ull i = start; i<=end; i++)
    {
        if (i & 1)
        {
            oddSum+=i;
        }
    }
    oddSumPromise.set_value(oddSum); //step 4: set value of PROMISE so that FUTURE can consume it.
}



int main()
{

    ull start = 0 , end = 1000000;

    promise<ull> oddSum; //step1 declare promise
    future<ull> oddFuture = oddSum.get_future(); //step 2: declare future using promise object
    
    cout<<"\nThread created!!"<<endl;
    thread t1(findOdd, move(oddSum), start, end); //step 3  pass PROMISE to the function to get value

    cout<<"waiting for Result!!"<<endl;

    cout<<"OddSum:"<<oddFuture.get()<<endl; //step 5: future fectches the value using get function

    //this saves time as the main thread and the t1 thread executes simultaneously to fetch result from the function.
    //imn normal cuircumstances main will wait till findodd completes and then proceed further

    cout<<"completed!!"<<endl;

    t1.join();
    return 0;
}