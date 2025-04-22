#include <iostream>

using namespace std;

void selectionSort(int a[], int size)
{
    for(int i=0;i<size; i++)
    {
        int min =i;
        for (int j=i+1; j<size;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(i!= min)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}


int main()
{
    int A[] = {6,4,2,5,1,3};
    int size = sizeof(A)/sizeof(A[0]);

    selectionSort(A, size);

    for (auto v : A)
    {
        cout<<v<<" ";
    }

    return 0;
}