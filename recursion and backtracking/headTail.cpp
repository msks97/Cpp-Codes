#include <iostream>

using namespace std;

void head(int n)
{
    if (n==0) return;

    head(n-1);

    cout<<"Head: n = "<<n<<endl;
}

void tail(int n)
{
    if (n==0) return;

    cout<<"Tail: n = "<<n<<endl;

    tail(n-1);

    
}

int main()
{

    int n = 5;
    head(n);
    tail(n);

    return 0;
}