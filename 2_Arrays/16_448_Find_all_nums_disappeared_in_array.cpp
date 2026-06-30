// given an array of n integers each integer is in range of [1,n] some elements disappear twice and other appear once. find all elements that do not repeat

// without using extra space must be done in O(1)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class sol
{
public:
    vector<int> FindDisappearingNums(vector<int> &nums)
    {
        vector<int> missingnums;

        // first we loop the array and mark the visited nums by flipping them to -ve
        for (int i = 0; i < nums.size(); i++)
        {
            int targetIndex = abs(nums[i] )-1; // we get the targetindex by using absolute ()

            // if targetindex is positive flip it to negative
            if (nums[targetIndex] > 0)
            {
                nums[targetIndex] = -nums[targetIndex];
            }
        }

        // now identify which pairs remain positive
        for (int i = 0; i < nums.size(); i++)
        {
            // if its positive i + 1 pair was never seen
            if (nums[i] > 0)
            {
                missingnums.push_back(i + 1);
            }
        }
        return missingnums;
    }
};

int main()
{
    sol obj;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = obj.FindDisappearingNums(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}