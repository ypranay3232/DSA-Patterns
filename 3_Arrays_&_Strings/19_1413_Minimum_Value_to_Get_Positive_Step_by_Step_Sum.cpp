#include <iostream>  
#include <vector>    
#include <algorithm> 
#include <climits>   

class Solution
{
public:
    int minStartValue(std::vector<int> &nums)
    {
        // Track the running sum as we add elements step-by-step
        int current_sum = 0;

        // Track the absolute lowest point the running sum hits (initialize to largest possible integer)
        int min_sum = INT_MAX;

        // Loop through each number in the array 
        for (int num : nums)
        {
            // Add the current number to our running total
            current_sum += num;

            // Keep the smaller value between our previous minimum and the new current sum
            min_sum = std::min(min_sum, current_sum);
        }

        // If min_sum is negative (e.g., -4), we need 1 - (-4) = 5 to keep the step-by-step sum at least 1.
        // If min_sum is positive, 1 - min_sum will be less than 1, so std::max will safely return 1.
        return std::max(1, 1 - min_sum);
    }
};

int main()
{
    Solution solution;

    std::vector<int> test_nums = {-3, 2, -3, 4, 2};

    int result = solution.minStartValue(test_nums);

    std::cout << "The minimum startValue is: " << result << std::endl;

    return 0;
}
