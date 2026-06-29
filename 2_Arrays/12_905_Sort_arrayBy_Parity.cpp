// Given an array, move all even integers to the beginning of array followed by odd integers.
// meaning rearrange integers in order as : even integers comes first then odd integers after even

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class sol
{
    public:
    vector<int> & SortArrayByParity(vector<int>& nums){
        // we create two pointers left,right which both points to starting and ending of array
        int left = 0;
        int right = nums.size()-1;

        // we loop array until left < right (a condition where both meet at middle)
        while(left< right){
            // check if left % 2 == 0 (left is even if yes move)
            if(nums[left] %2 ==0){
                left++;
            }//if right is odd just move because its in correct place (even at left, odd at right)
            else if(nums[right] %2 !=0){
                right --;
            }
            else{
                // if left is not even (odd) and right is not odd (even) we swap both and move
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};

int main(){
    sol obj;
    vector<int> nums = {3,1,2,4};

    obj.SortArrayByParity(nums);

    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}