// given an array of integers sorted in non decreasing order, return an array of squares of each number in sorted order.

#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    vector<int> sortedsquares(vector<int> &nums)
    {
        // we create two pointers right, left and
        // k (pointer points to ans array and ans store results (from back to front) so that largest result can be stored at back and smallest can be stored at front)
        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;
        vector<int> ans(nums.size());

        // while left < right we pick two nums (a,b) and get their square
        while (left <= right)
        {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];

            // now we check if a > b (if yes we store it in backside last of ans array)
            if (a > b)
            {
                ans[k] = a;
                left++;
                k--; // k decreases and it moves one position front
            }
            else
            {
                ans[k] = b;
                right--;
                k--;
            }
        }
        return ans;
    }
};

int main()
{
    solution obj;
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = obj.sortedsquares(nums);
    cout<<"[";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << "]" << endl;

    return 0;
}