// 2824. Count pairs sum whose sum is less than target. Given an array of length n, target , return number of pairs where 0 <= i< j<n. where nums[i] + nums[j] < target.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    int countpairs(vector<int> &nums, int target)
    {
        // first we sort the array in non decreasing order to use two pointers
        sort(nums.begin(), nums.end());

        // two pointers left and right
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;

        while (left < right)
        {
            // check if left + right < target or not if not decrement the right, because it has largest numbers in array.
            if (nums[left] + nums[right] < target)
            {
                // if left + right < target all elements between left and right form pairs
                count += (right - left);
                left++;
            }
            else
            {
                right--;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {-1, 1, 2, 3, 1};
    int target = 2;

    solution obj;

    int result = obj.countpairs(nums, target);
    cout << "Test Case 1 Result: " << result << " (Expected: 3)\n";

    return 0;
}