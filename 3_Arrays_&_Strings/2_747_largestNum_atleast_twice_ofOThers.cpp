// Given an integer array nums where largest value is unique (no copy). we have to find the largest number which is twice large as every other number. return its index.

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class sol{

    public:
    int LargestNumIndex(vector<int>& nums){
        // we create two pointers
        int maxval = -1; int secondmax = -1; int maxvalIndex = -1;
    
        // now loop the array and check if current num is > max then swap
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>maxval){
                secondmax = maxval; //second max val is maxval
                maxval = nums[i];//maxval is nums[i] val
                maxvalIndex = i;//update the maxvalIndex 
            }//if nums[i] > secondmax update it
            else if(nums[i] > secondmax){
                secondmax = nums[i];
            }
        }
        return (maxval >= secondmax * 2) ? maxvalIndex : -1;
    }
};

int main(){
    sol obj;
    vector<int> nums = {3,6,1,0};
    cout<<obj.LargestNumIndex(nums);

    return 0;
}