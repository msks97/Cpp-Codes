#include <iostream>
using namespace std;

int fibHead(int n) //head
{
    if (n==0) return 0;
    if (n==1) return 1;

    return fibHead(n-1)+fibHead(n-2);
}

int fibTail(int n, int a, int b)
{
    if(n == 0) return a+b;
    
    return fibTail(n-1, b ,a+b);
}


int main()
{
    int n=7;
    cout<<"Head type: Fibonacci's "<<n<<"th number is: "<<fibHead(n)<<endl;

    cout<<"Tail type: Fibonacci's "<<n<<"th number is: "<<fibTail(n,0,1)<<endl;

    return 0;
}