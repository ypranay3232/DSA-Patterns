#include<iostream>
#include<vector>

using namespace std;

void reversearray(vector<int>& nums){
    // create two pointers
    int left = 0;
    int right = nums.size()-1;

    // check if left < right 
    while(left<right){
        // if yes then swap left with right and move pointers
        swap(nums[left], nums[right]);

        left++;
        right--;
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    reversearray(nums);

    // print the vector
    for(int x:nums){
        cout<<x<<endl;
    }
    return 0;
}