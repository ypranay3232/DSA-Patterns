// given an binary array nums return the max no of consecutive ones in array 
/*
we have an array with 0s and 1s. 
we look for 1 if we find consecutive 1's [1,1,1] out count = 3
But if we encounter any 0 in list [1,1,1,0,1] our max count will break and we have to restart,we keep moving by counting [1,1,0,1,1,1] here after 0 we restart counting so max consecutive 1s are 3

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class sol{
    public:

    int FindConsecutiveones(vector<int>& nums){
        int max_continuous_count = 0;
        int count = 0;

        // we loop the array and check if nums has any 1, if yes we update count ++
        for(int num : nums){
            if(num == 1){
                count++;
                // and after updating count we update max continuous count by checking If the current streak is bigger than old record, update this new record! if not its same.
                max_continuous_count = max(count,max_continuous_count);
            }else{
                // if count is broken (encountered 0 we reset)
                count = 0;
            }
        }
        return max_continuous_count;
    }
};
int main(){
    sol obj;
    vector<int> nums = {1,1,0,1,1,1};
    int result = obj.FindConsecutiveones(nums);
    cout<<"The  maximum number of consecutive 1's are : "<<result<<endl;

    return 0;
}