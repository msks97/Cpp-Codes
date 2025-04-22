#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin>>a>>b;
    int c=0;
    
    try
    {
        if(b==0)
        {
            throw "Divide by zero is not possible";
        }

        c=a/b; //exception
    }
    catch(const char *e)
    {
        cout<<"Exception occured:"<<e<<endl;
    }
    
    cout<<c<<endl;
}