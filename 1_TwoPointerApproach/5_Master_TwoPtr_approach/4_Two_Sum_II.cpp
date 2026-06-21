// This problem two sum II is pretty simple here : we have an sorted array in non decreasing order and here instead of returning the index we return position that starts with 1.

// Given an 1 indexed array of integers. which is already sorted find numbers such that they add up to the target.
// so we the array is already sorted we can just use two pointers to return two indexes.

#include <iostream>
#include <vector>

using namespace std;

class solution
{

public:
    vector<int> twosum(vector<int> &nums, int target)
    {
        // we create two pointers
        int left = 0;
        int right = nums.size() - 1;

        // first we check the base condition
        while (left < right)
        {
            // we get the sum via adding two indexes
            int current_sum = nums[left] + nums[right];
            // if we find the sum == target we return the index
            if (current_sum == target)
            {
                return {left + 1, right + 1}; // because the array is 1 indexed so to get rid of 0 index we add + 1 to both.
            }
            // if sum < target increment left to move right
            else if (current_sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {};//the problem guarantee a solution but just in case we return empty if no solution 
    }
};

int main(){
    solution obj;
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = obj.twosum(nums,target);
    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;
    return 0;
}
