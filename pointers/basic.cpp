#include <iostream>

using namespace std;

int main()
{
    int A[5] = {2,4,6,8,10};
    int *p = A;

    int b=5;
    int *q = &b;

    for(int i = 0 ; i<5; i++)
    {
        cout<<A[i]<<endl;
        cout<<i[A]<<endl;
        cout<<*(A+i)<<endl;
        cout<<A+i<<endl;
        cout<<"\n";
    }


    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl; //A[0] value
    cout<<p[-2]<<endl; //a[-2] value
    cout<<*(p+2)<<endl; //a[2] value
    cout<<*p<<endl; //A[0] value

    cout<<"\n";
    p+=2;
    cout<<*p<<endl; //A[2] value
    cout<<*(p+2)<<endl; //A[4] value
    cout<<"\n";

    cout<<*q<<endl;
    cout<<q<<endl;
    q+=1;
    cout<<q<<endl;
    cout<<*q<<endl;


}