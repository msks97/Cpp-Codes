#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> out(2,0);
    int i=0;
    int j=1;

    while(i<nums.size()-1 )
    {
        if(nums[i]+nums[j] == target)
        {
            out[0] = nums[i];
            out[1] = nums[j];
        }

        if(j==nums.size()-1)
        {
            i++;
            j=i+1;
        }
        else
        {
            j++;
        }

    }

    return out;
}

int main()
{
    vector<int> numbers = {7,11,2,1};
    int target = 9;

    vector<int> output = twoSum(numbers, target);

    cout<<"["<<output[0]<<", "<<output[1]<<"]"<<endl;

    return 0;

}