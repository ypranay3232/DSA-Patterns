// given an array calculate the pivot index of array, The pivot index is index where all elements are strictly to the left side sum is equal to right side sum 

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class sol{
    public:
    int pivotindex(vector<int> & nums){
        // first we calculate the total sum of array 
        int totalsum = accumulate(nums.begin(), nums.end(),0);
        // now we create two pointers : leftsum, rightsum 
        int leftsum = 0; int rightsum = 0; 

        // now we loop the array 
        for(int i = 0;i<nums.size();i++){
            // now get right sum
            rightsum = totalsum - leftsum - nums[i];

            // now check if left == right if yes we got pivot
            if(leftsum == rightsum){
                return i;
            }
            // update the leftsum
            leftsum += nums[i];
        }
        // if no pivot index found return -1.
        return -1;

    }
};

int main(){
    sol obj;
    vector<int> nums = {1,7,3,6,5,6};
    cout<<obj.pivotindex(nums);
    
    return 0;
}