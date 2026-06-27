// given an array nums and val, remove all val in array nums.
// cannot use extra space, Order does not matter
// You need to return k, which is the no of elements in nums that are not equal to val.

/*
Example : 
Input: nums = [3, 2, 2, 3], val = 3
We need to remove all 3s.
The remaining elements are two 2s.
Your function should return $k = 2$, and the first two elements of nums should be 2.
nums could look like [2, 2, _, _] (the underscores can be anything).

*/

#include<iostream>
#include<vector>

using namespace std;

class sol{
    public:

    int removele(vector<int>& nums, int val){
        int k = 0;//  k points to next valid elements which are not val

        // loop the array
        for(int i = 0; i<nums.size(); i++){
            // if current element is not val (which we have to remove) then k = current ele
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main(){
    sol obj;

    vector<int> nums = {3,2,2,3};
    int val = 3;

   int k = obj.removele(nums,val);
    cout<<"array after removing elements"<<endl;

    for(int i = 0; i<k; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}