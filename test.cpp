#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n==0) return 1;

    return n * factorial(n-1);
}

int factfor(int n)
{
    if( n== 0) return 1;
    int fact = 1;

    for( int i = 1; i<= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int n = 5;
    cout<<"Factorial of"<<n<<"is: "<<factfor(n);

    return 0;
}