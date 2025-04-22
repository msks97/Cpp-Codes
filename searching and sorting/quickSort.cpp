#include <iostream>

using namespace std;

void swap(int array[], int i1, int i2)
{
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}

 int pivot(int array[], int pivotIndex, int endIndex)
{
    int swapIndex = pivotIndex;
    for (int i = pivotIndex+1; i<=endIndex; i++)
    {  
        if(array[pivotIndex]>array[i])
        {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex>= rightIndex) return;

    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex-1);
    quickSort(array, pivotIndex+1, rightIndex);


}

int main()
{
    int A[] = {4,6,1,7,3,2,5};
    int size = sizeof(A)/sizeof(A[0]);

    quickSort(A, 0, size-1);

    for (auto v : A)
    {
        cout<<v<<" ";
    }
}