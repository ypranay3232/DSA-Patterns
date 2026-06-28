// given an array check if two indices i,j are different and arr[i] = 2 * arr[j], i is double of j.

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class sol{
    public:
    bool checkIfExist(vector<int>& nums){
        unordered_set<int> seen;

        for(int x : nums){
            if(seen.count(2*x)){
                return true;
            }
            if(x %2 ==0 && seen.count(x/2)){
                return true;
            }
            seen.insert(x);
        }
        return false;
    }
};
int main(){
    sol obj;
    vector<int> nums = {10,2,5,3};

    if(obj.checkIfExist(nums)){
        cout<<"true";
    }else{
        cout<<"false";
    }
    return 0;
}