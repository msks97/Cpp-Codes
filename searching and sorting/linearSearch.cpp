#include <iostream>
using namespace std;

void search(int arr[], int n, int a)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == a)
            cout<<"Item is found at index: "<<i <<endl;
    }
}

int main()
{
    int arr[] = {1,5,3,6,7,9,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    search(arr,n,9);
    return 0;
}