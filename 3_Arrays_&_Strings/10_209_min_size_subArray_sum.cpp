// given an array nums, target,return the minimal length of subarray whose sum is >= target. if no such sub array return 0.

// ex : [2,3,1,2,4,3] here min sub array is (4,3) so target = 4+3 = 7. its length as output : (2)
// we use sliding window approach to find subarray sum.

/*
You're given an array and a target.

nums = [2,3,1,2,4,3]
target = 7

Find the smallest continuous subarray whose sum is at least 7.

Possible subarrays from : nums = [2,3,1,2,4,3]

[2,3,1,2] = 8 (length 4)
[3,1,2,4] = 10 (length 4)
[2,4,3] = 9 (length 3)
[4,3] = 7 (length 2)  <-- smallest

Answer = 2

*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class sol
{
public:
    int minSubarray(vector<int> &nums, int target)
    {
        // two variables which start from index 0 and right end up at end of window.
        int left = 0;
        int right = 0;
        int currentSum = 0;// keeps track of total sum
        int min_length = INT_MAX;//stores shortest valid sliding window size found so far, we initialize it with max value so that any window size is small 

        for (; right < nums.size(); right++)//move the right pointer
        {
            // when we loop the windows expands so add a new number: [2] then [2,3] then [2,3,1]
            currentSum += nums[right];
            
            // if currentsum >= hits target  
            while (currentSum >= target)
            {
                // we try to make the currentsum smaller by removing numbers from left such that we get min sub array size
                min_length = min(min_length, right - left + 1);
                // removing left most number from window
                currentSum -= nums[left];
                left++;
            }
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};
int main(){
    sol obj;

    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int result =  obj.minSubarray(nums,target);
    cout<<"The Length is : "<<result<<endl;
    return 0;
}