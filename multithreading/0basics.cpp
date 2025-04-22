#include<chrono>
#include<iostream>
#include<thread>

using namespace std;

//callable object -  thread entry object
void Hello()
{
    cout<<"Hello"<<endl;
}

void Hello2(string str)
{
    cout<<str<<endl;
}

int main()
{
    //chrono::seconds sec(10);
    //std::cout << "Seconds: " << sec.count() << std::endl;

    //create an std::thread object
    //and pass the task function to the constructor
    thread thr(Hello);

    thread thr2(Hello2,"Hello from Thread");

    //wait for thread to complete
    
    thr.join();
    thr2.join();

}