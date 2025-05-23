#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int totalCount = 0;
    int currentSum = 0;
    // {prefix: number of occurrence}
    unordered_map<int, int> freq; // To store the frequency of prefix sums

    for (int num : nums) {
        currentSum += num;
        if (currentSum == goal){
            totalCount++;
        }

        // Check if there is any prefix sum that can be subtracted from the current sum to get the desired goal
        if (freq.find(currentSum - goal) != freq.end()){
            totalCount += freq[currentSum - goal];
        }

        freq[currentSum]++;
    }

    return totalCount;
}

int main()
{
    int goal =2;
    vector<int> nums = {1,0,1,0,1};

    int result = numSubarraysWithSum(nums, goal);

    cout<<"Number of subarrays are :"<<result<<endl;
    
    return 0;
}