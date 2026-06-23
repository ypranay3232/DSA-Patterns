// Leetcode 75 : sort colors Given an array nums with n objects with colors red(0),white(1),blue(2). we have to sort them without using library sort()

// we use three pointer approach : low = tracks where next 0 should go (starts at 0)
// mid = scans entire array left to right, high = tracks where next 2 should go

// The core idea is to use mid to scan array and place left of low with all 0's and right of high with 2's. In between will be 1's

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class solution{

    public:
    void sortColors(vector<int> & nums){
        int low = 0; int mid = 0; int high = nums.size()-1;

        while (mid <=high)//if i< j (0 < end)
        {
            // check if mid == 0 because it belongs to low we swap it with that 
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            // if mid == 1 it is already in middle of array because left is 0 middle is 1 so we just move mid.
            else if (nums[mid] == 1){
                mid ++;
            }
            // else if mid == 2 we throw that to end by swapping with high
            else{
                swap(nums[mid],nums[high]);
                high --;
            }
        }
        
    }
};

int main() {
    solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    sol.sortColors(nums);

    cout << "After sorting:  ";
    for (int x : nums) cout << x << " ";
    cout << "\n";

    return 0;
}