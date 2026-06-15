// given an array of numbers sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order. (.i.e. return result in a sorted order)


// given an array = [-4,-1,0,3,10] so sorted values would be : [16,1,0,9,100] as we can see that we made -ve values positive. we can see that the array is in non-decreasing order so the right side of array would always be the largest number (n-1)

// so we take index = n-1, because we need sorted array for result, so we store values from backside of array ==> [, , , , ,100]--> [, , , , 9,100]



#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> sortedsquares(vector<int>& nums){
        // get the size of the array and also create a result array with the size of nums.
        int n = nums.size(); 
        vector<int> result(n);

        // now create two pointers and an index so we can store the results from backside of array
        int left = 0;
        int right = n-1;
        int index = n-1;

        // while left <= right get the squares 
        while (left <= right)
        {
            int leftsquare = nums[left] * nums[left];
            int rightsquare = nums[right] * nums[right];

            // now compare : if leftsquare is > right.No because right would always be largest (n-1)
            if(leftsquare > rightsquare){
                result[index] = leftsquare; 
                left++;
            }else{
                result[index] = rightsquare; //put the largest here in index and move 
                right--;
            }
            // move the index pointer to backwards to place next value in index.
            index --;
        }
        return result;
    }
};


int main(){
    Solution obj;
    vector<int> nums = {-4,-1,0,3,10};

    vector<int> output = obj.sortedsquares(nums);
    cout<<"sorted array"<<endl;
    for(auto x: output){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}