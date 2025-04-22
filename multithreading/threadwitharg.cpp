#include <iostream>
#include <thread>

using namespace std;


void hello(string && str)
{
    cout<<"\n"<<str<<"\n";
}

int main()
{
    string str = "Hello";

    thread thr(hello, std::move(str));
    thr.join();

    cout<<"Is str empty:"<<(str.empty() ? " Yes":" No");

}