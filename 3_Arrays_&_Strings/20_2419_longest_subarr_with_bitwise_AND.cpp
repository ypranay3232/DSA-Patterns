// You are given an integer array nums. You need to find the length of the longest subarray that achieves the maximum possible bitwise AND value.

// NOTE : The question does not ask you to return the maximum AND value itself. It asks you to find the length of the longest subarray that produces that value.

// can be solved by finding the longest contiguous run of the array’s maximum value. Because a bitwise AND operation can never increase a number, the absolute highest AND value you can achieve from any subarray is simply the maximum number in the entire array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        // length for storing longest result, maxi for max num so far
        int l = 0;
        int maxi = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            // Checks if the current element nums[i] is greater than or equal to the maximum element seen so far (maxi). If it is smaller skip.
            if (nums[i] >= maxi)
            {
                // store value of curr max val in m, a ptr for i, r for counting streak of longest length
                int m = nums[i];
                int j = i;
                int r = 0;
                // scans forward as long as the elements are identical to m. It increments the streak counter r and moves the j forward.
                while (j < nums.size() && nums[j] == m)
                {
                    r++;
                    j++;
                }
                // If the current element m matches the maxi found so far, it updates l
                if (m == maxi)
                    l = max(l, r);
                else
                {
                    // If m is strictly greater than maxi, the old maximum is obsolete. It resets the longest length l to the current streak r and updates maxi to this new, larger value m.
                    l = r;
                    maxi = m;
                }
                // Updates the outer loop index i to j - 1. Since the for loop automatically increments i at the end of the iteration, setting it to j - 1 ensures that the next iteration starts exactly at index j, avoiding redundant checks.
                i = j - 1;
            }
        }
        // we return l as the final result.
        return l;
    }
};

int main()
{
    Solution solver;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 3, 2, 2};
    cout << "Test Case 1 Result: " << solver.longestSubarray(nums1) << " (Expected: 2)" << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test Case 2 Result: " << solver.longestSubarray(nums2) << " (Expected: 1)" << endl;

    return 0;
}
