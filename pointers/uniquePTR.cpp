#include <iostream>
#include <memory>
using namespace std;

class Demo
{
    public:
        Demo(){cout<<"Constructor"<<endl;}
        ~Demo(){cout<<"Destructor"<<endl;}
        void greet() { cout<<"Hello from unique ptr"<<endl;}
};


int main()
{
    unique_ptr<Demo> uptr = make_unique<Demo>();
    uptr->greet();

    //unique_ptr<Demo> uptr2 = uptr; //cannot copy
    unique_ptr<Demo> uptr3 = move(uptr);
    if(!uptr) cout<<"uptr is now nullptr"<<endl;

    Demo *ptr = uptr.release();
    if(!ptr) cout<<"ptr is now nullptr"<<endl;
    ptr->greet();  /// for some reason this Works any explanation???
    uptr.reset();

    return 0;
}