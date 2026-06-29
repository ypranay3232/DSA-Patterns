// given an array move all 0's in array to end of array. Without creating a new array, and we must maintain Relative order : meaning non 0 numbers must be in same order  

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class sol{
    public:

    void moveZeros(vector<int>& nums){
        // first we create 2 pointers : i collects non zero elements, j finds non zeros and we swap j with i.
        int i = 0;
        // now we loop the array 
        for(int j = 0; j<nums.size();j++){
            // check if j ! = 0 if j is not a zero it must be an number, so swap j with i, move i
            if(nums[j] != 0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};

int main(){
    sol obj;
    vector<int> nums = {0,1,0,3,12};

    obj.moveZeros(nums);
    // print the array 
    for(int x : nums){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;

}