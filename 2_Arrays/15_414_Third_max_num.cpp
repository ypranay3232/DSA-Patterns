// given an array of nums, return third distinct (no copy allowed) max number, if the third does not exist return the max number 

// Example: nums = [2, 2, 3, 1]
// The distinct maximums are: 1st max = 3, 2nd max = 2, 3rd max = 1. (The extra 2 is ignored).
// Output: 1

// we use three variable approach : 

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class sol{
    public:

    int ThirdMax(vector<int> & nums){
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        // we loop the array 
        for(int x : nums){
            // check for duplicates if a num exist in first or second or third its a duplicate
            if(x == first || x == second || x == third){
                continue;
            }

            // now update the values if x(current num) is > first we assign it to first
            if(x > first){
                third = second;
                second = first;
                first = x;
            }
            else if(x > second){
                third = second;
                second = x;
            }else if(x > third){
                third = x;
            }
        }
        return (third == LLONG_MIN) ? first : third;
    }
};

int main(){
    sol obj;
    vector<int> nums = {3,2,1};
    cout<<obj.ThirdMax(nums);
    return 0;
}