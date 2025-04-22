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

    shared_ptr<Demo> sptr2 = sptr;
    sptr2->greet();

    cout<<"Use count: "<<sptr.use_count()<<endl;
    cout<<"Use count: "<<sptr2.use_count()<<endl;

    sptr.reset();
    cout<<"Use count after reset"<<sptr.use_count()<<endl;
    cout<<"Use count after reset"<<sptr2.use_count()<<endl;



    return 0;
}