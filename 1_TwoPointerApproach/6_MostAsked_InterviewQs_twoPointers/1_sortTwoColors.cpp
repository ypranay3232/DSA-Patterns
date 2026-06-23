// given an array nums that contains o or 1. Sort the array in ascending order. Its a simplified version of Dutch national flag problem.

// Approach is pretty simple : create two pointers.
// while left < right,
// if left == 0 left ++
// if right == 1 right --.
// if left ==1 and right == 0 both are in wrong spot so swap

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class solution
{
public:
    void SortZeroesOnes(vector<int> &nums)
    {
        // first we create two pointers
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            // check if left == 0
            if (nums[left] == 0)
            {
                left++;
            }
            else if (nums[right] == 1)
            {
                right--;
            }else{
                // now if left contains 1 or right contains 0 swap both
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
    }
};

int main()
{
    solution obj;
    vector<int> nums = {1, 0, 1, 1, 0, 0, 1, 0};
    cout << "Original Array " << endl;
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    cout << "Sorted Array " << endl;
    obj.SortZeroesOnes(nums);
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}