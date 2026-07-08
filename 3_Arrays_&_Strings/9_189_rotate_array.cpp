// given an array rotate the array to right by k steps where k is non negative 

// ex : [1,2,3,4,5,6,7] --> where k = 3; --> output : at first rotation [7,1,2,3,4,5,6] at second rotation [6,7,1,2,3,4,5] --> third rotation [5,6,7,1,2,3,4]

// we use algorithm to rotate array 
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class sol{
    public:
    void rotate(vector<int> & nums, int k){
        // ensures that if k rotation is within range
        k = k % nums.size();
        // start array and get k and move from k to end
        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};

int main(){
    sol obj;

    vector<int> nums = {1,2,3,4,5};
    int k = 3;

    obj.rotate(nums,k);
    for(int x: nums) cout<<x<<" ";
    cout<<"\n";

    return 0;
}