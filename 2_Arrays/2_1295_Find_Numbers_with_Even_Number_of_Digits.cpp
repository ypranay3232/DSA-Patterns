// Given an array of integers, return how many of them contain even numbers.
/*
Example: nums = [12, 345, 2, 6, 7896]
Let's look at the digit count for each number:

12 --> has 2 digits (1,2 = 2is even) -->                            Count = 1
345 --> has 3 digits (3,3,5 = 3 is odd)2 ---> has 1 digit (1 is odd)
6 --> has 1 digit (6 only single digit (1) so 1 is odd)
7896 ---> has 4 digits (4 is even) -->                               Count = 2

*/

// // To count digits we can use two ways:
// 1) String way: to_string() which takes O(log N) space
// 2) Math way: divide number by 10 repeatedly until it becomes 0. Takes O(1) auxiliary space (Optimized)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumWithEvenNumberOfDigits(vector<int>& nums) {
        // Counter to keep track of numbers that have an even number of digits
        int countEven = 0;
        
        // Traverse each number in the array 
        for (int num : nums) {
            int digits = 0;
            // Create a copy of num in temp because the while loop will modify it
            int temp = num;

            // Count digits by dividing by 10 until the number becomes 0
            while (temp > 0) {
                digits++;
                temp /= 10; // Cuts off the last digit
            }
            
            // Check if the final digit count is even
            if (digits % 2 == 0) {
                countEven++; // Increment our main answer counter
            }
        }
        return countEven;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {12, 345, 2, 6, 7896};
    
    int result = obj.findNumWithEvenNumberOfDigits(nums);
    cout << "The number of elements with an even number of digits is: " << result << endl;

    return 0;
}