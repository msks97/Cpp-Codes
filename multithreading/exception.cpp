#include<chrono>
#include<iostream>
#include<thread>

using namespace std;

//task function
void Hello()
{
    throw std::exception();
    cout<<"Hello, thread \n"<<endl;
}

int main()
{
    try
    {
        thread thr(Hello);
        thr.join();
    }
    catch(std::exception& e)
    {
        std::cout<<"Exception caught "<< e.what() << '\n';
    }
    

    cout<<"\nFinished.";

}