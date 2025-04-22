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
    shared_ptr<Demo> sptr = make_shared<Demo>();
    sptr->greet();

    weak_ptr<Demo> wptr = sptr;
    weak_ptr<Demo> wptr2 = wptr;

    cout<<"Use count: "<<sptr.use_count()<<endl;

    auto temp = wptr.lock();

    if(wptr.expired()) cout<<"ptr is now nullptr"<<endl;
    sptr.reset();
    if(wptr.expired()) cout<<"wptr after reset is now nullptr"<<endl;
    wptr.reset();
    if(wptr.expired()) cout<<"wptr after reset is now nullptr2"<<endl;




    return 0;
}