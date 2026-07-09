// given an array nums of 2n integers. goal is to group them into n pairs.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class sol{
    public:
    int arrayPairSum(vector<int> & nums){
        // first we sort array 
        sort(nums.begin(),nums.end());
        int sum = 0;
        // loop the array and add the nums to sum, here in loop we add two and two pairs as i+=2
        for(int i = 0;i<nums.size();i+=2){
            sum += nums[i];
        }
        return sum;
    }
    
};

int main(){
    sol obj;
    vector<int> nums = {1,4,3,2};
    int result = obj.arrayPairSum(nums);
    cout<<"Result is : "<<result<<endl;
    return 0;
}