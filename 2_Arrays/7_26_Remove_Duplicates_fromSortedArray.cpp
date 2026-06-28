// Given an integer array nums sort it in non decreasing order, remove duplicates (in place --> dont create new array)such that each element appears only once, return no of unique elements (k)

// We can see that since array is sorted the duplicates comes in order

// we use two pointer approach : i , k both point to starting index, we move i and check with previous index if same skip. 

#include<iostream>
#include<vector>
using namespace std;

class sol{
    public:
    int removeDuplicates(vector<int> & nums){
        // we know that first element is always unique so 
        int k = 1;
        for(int i =1; i<nums.size();i++){
            // check if current index does matches with previous its not a duplicate 
            if(nums[i] != nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }

};

int main(){
    sol obj;

    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = obj.removeDuplicates(nums);

    cout<<"Array after duplicates"<<endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout<<endl;
}