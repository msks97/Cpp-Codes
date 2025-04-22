#include <iostream>
using namespace std;

int binarySearch(int nums[], int low, int high, int item)
{
    if(low > high) return -1;

    int middle = low + (high- low)/2;

    if(nums[middle] == item) return middle;

    if(item < nums[middle])
        return binarySearch(nums, low, middle-1, item);
    else
    return binarySearch(nums, middle + 1, high, item);
}



int main()
{
    int nums[] = {1, 30, 40, 50, 60, 70, 80, 90, 100 };
    int item  = 50;
    int n = sizeof(nums)/sizeof(nums[0]);
    cout <<" Index: "<<binarySearch(nums, 0, n-1, item)<<endl;
    return 0;
}