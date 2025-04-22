#include <iostream>
#include <exception>

using namespace std;

//example exception class
/*class exception
{
    protected:
        string msg;
    public:
        exception(string msg)
        {
            this->msg = msg;
        }

        string what()
        {
            return msg;
        }
};*/



int main()
{
    try
    {
        int *p = new int[100000000000];
        cout<<"Memory allocation is successful";
        delete []p;
    }
    catch(const  runtime_error &e)
    {
        cout<<"Exception occured at line 9 -> "<<e.what()<<endl;
    }
}