#include <iostream>
#include <memory>

using namespace std;

int main()
{
    const int arrSize = 5;

    //c++11 way    
    unique_ptr<double> myPtr(new double); 
    *myPtr = 3.14;
    cout<<"\nPointer is: "<<*myPtr<<endl;

    //c++14 way
    unique_ptr<double> myPtr2 = make_unique<double>();
    *myPtr2 = 3.14;
    cout<<"\nPointer2 is: "<<*myPtr2<<endl;

    //using auto
    auto myArray = make_unique<int[]>(arrSize);
    for (int i=0; i<arrSize;i++)
    {
        myArray[i] = i*2;
    }

    for (int i=0; i<arrSize;i++)
    {
        cout<<myArray[i]<<endl;
    }

    //use move opteration to changethe ownership of unique pointers since they own the object. 
    //Unless then other smart pointers wont be able to point at that object

    //move function
    unique_ptr<double> otherPtr = move(myPtr);
    cout<<"\nOther Pointer is: "<<*otherPtr<<endl; 

    return 0;

}