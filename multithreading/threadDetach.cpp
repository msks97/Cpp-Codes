#include<chrono>
#include<iostream>
#include<thread>

using namespace std;

//callable object -  thread entry object
void Hello()
{
    cout<<"Hello"<<endl;
}

int main()
{
    thread thr(Hello);
    
    thr.join();


}