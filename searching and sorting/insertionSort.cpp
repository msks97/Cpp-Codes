#include <iostream>

using namespace std;

void insertionSort(int a[], int size)
{
    for (int i=1; i<size;i++)
    {
        int temp = a[i];
        for(int j=i-1;j>-1;j--)
        {
            if(temp<a[j])
            {
                a[j+1]=a[j];
                a[j] = temp;
            }
        }
    }
}


int main()
{
    int A[] = {6,4,2,5,1,3};
    int size = sizeof(A)/sizeof(A[0]);

    insertionSort(A, size);

    for (auto v : A)
    {
        cout<<v<<" ";
    }

    return 0;
}