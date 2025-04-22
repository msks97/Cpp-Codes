#include <iostream>

using namespace std;

void bubbleSort(int array[], int size) //sysntactiv notation to int * array
{
    for( int i = size-1; i>0; i--) //   'OR'  for( int i = 0; i<size-1;i++)
    {
        for (int j=0; j<i; j++)  //j=0;j<size-i
        {
            if (array[j]> array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {6,4,2,5,1,3};
    int size = sizeof(A)/sizeof(A[0]);

    bubbleSort(A, size);

    for (auto v : A)
    {
        cout<<v<<" ";
    }

    return 0;
}