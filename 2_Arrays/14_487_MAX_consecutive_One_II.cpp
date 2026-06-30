// Given an binary array return the max no of consecutive ones in the array and you can flip utmost one zero.

// we use dynamic sliding window approach 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class sol{

    public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int ans = 0; int lastzeroIndex = -1; 
        int left = 0;
        for(int right = 0;right<nums.size();right++){
            // check if right is 0
            if(nums[right] == 0){
                // move left pointer past the previous 0.
                left = lastzeroIndex + 1;
                lastzeroIndex = right;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }

};

int main(){
    sol obj;
    vector<int> nums = {1, 0, 1, 1, 0}; //1,0,1,1,0 ==> if we flip any 0 to 1, we get four 1's

    cout<<obj.findMaxConsecutiveOnes(nums);
    return 0;
}