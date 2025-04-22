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

    thread thr2(Hello2,"Hello2 from Thread");

    cout<<"Navite handle hello: "<<thr.native_handle()<<endl;
    cout<<"Navite handle hello2: "<<thr2.native_handle()<<endl;

    //pausethread
    std::this_thread::sleep_for(10s);

    //thread ID
    cout<<"threadID for thr: "<<thr.get_id()<<endl;
    cout<<"threadID for thr2: "<<thr2.get_id()<<endl;
    
    //wait for thread to complete
    thr.join();
    thr2.join();

    cout<<"Navite handle hello: "<<thr.native_handle()<<endl;
    cout<<"Navite handle hello2: "<<thr2.native_handle()<<endl;



}