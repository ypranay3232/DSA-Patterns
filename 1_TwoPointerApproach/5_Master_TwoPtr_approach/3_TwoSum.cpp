// leetcode first question : given an array of integers nums and target, and return indices (position) of the numbers which add up to the target
// (.i.e. we take two numbers from array and add them if their sum add up to target we return their index position)

// The catch here is you cannot use the same element twice. And here we only have one solution. And the order does not matter. ascending or descending etc.

// ex: we have num = [2,11,7,15], target = 9, only one solution (7 + 2) = target 0.

// Logic : instead of thinking it as : A + B = target. we think as (B = Target - A). Here B is the compliment.
// ex :we have a card 7, target 10. (10 - 7 = 3) so we just have to find card 3. so we get target.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solution
{
public:
    // we create a vector function that contains a nums array and a target.
    vector<int> twosum(vector<int> &nums, int target)
    {
        // now we define an unordered map which contains keys = seen number and values = index
        unordered_map<int, int> seenNumbers;

        // now we loop the array
        for (int i = 0; i < nums.size(); i++)
        {
            // we get the current number and we apply formula (B = Target - A )
            int currentNum = nums[i];
            int compliment = target - currentNum;

            // check if unordered map has compliment in entire map.
            if (seenNumbers.find(compliment) != seenNumbers.end())
            {
                // if exist we return compliment into currentnum
                return {seenNumbers[compliment], i};
            }
            else
            {
                // if element not exist in map then move seennumbers map
                seenNumbers[currentNum] = i;
            }
        }
        return {};
    }
};

int main()
{
    solution solver;

    // Test Case: nums = [2, 11, 7, 15], target = 9
    vector<int> nums = {2, 11, 7, 15};
    int target = 9;

    vector<int> result = solver.twosum(nums,target);

    // Output the results
    if (!result.empty())
    {
        cout << "Indices found: [" << result[0] << ", " << result[1] << "]" << endl;
        cout << "The numbers are: " << nums[result[0]] << " and " << nums[result[1]] << endl;
    }
    else
    {
        cout << "No two sum solution found." << endl;
    }

    return 0;
}