#include <iostream>

using namespace std;

int factorial(int n) //head recursion
{
    if(n==0)
        return 1;
        
    return n * factorial(n-1);
}

int fact(int n, int acc) //tail recursion
{
    if(n==0)
    {
        return acc;
    }
    

    return fact(n-1,n*acc);
    
}

int main()
{
    int n=4;
    cout<<"Factorial of ";
    //cin >> n;
    cout<< " is: "<<factorial(n)<<endl;

    cout<<"Factorial of ";
    //cin >> n;
    cout<< " is: "<<fact(n,1)<<endl;

     return 0;
}