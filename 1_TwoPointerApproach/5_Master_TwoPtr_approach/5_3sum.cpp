// Given an array of integers and we have to find all the triplets in an array which add up to the sum. (.i.e. Find 3 numbers which add up to the sum) and no reusing elements i,j,k must be unique 


// so what comes to the mind is using 2 pointers approach but we use 3 variables 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
    // we need a vector of vector because we have triplets of i,j,k which are kept inside a vector so a vector which holds another vector results
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> results;
        int n = nums.size()-1;//we get the size
        if (n < 3) return results; // Safety check

        // now sort the array 
        sort(nums.begin(), nums.end());

        // now loop the i til j-1
        for(int i =0;i<n-2;i++){
            // if sum is < 0 because no 3 numbers sum < 0
            if(nums[i]>0){
                break;
            }

            // skip duplicates 
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            // now we create j,k pointers
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];

                // if sum is 0 return the results into array
                if(sum == 0){
                    results.push_back({nums[i], nums[j],nums[k]});
                    // when encountered duplicates move 

                    while (j<k && nums[j] == nums[j+1])
                    {
                        j++;
                    }
                    while (j<k && nums[k] == nums[k-1] )
                    {
                        k--;
                    }

                    j++;
                    k--;                   
                }
                // if sum < 0 move j else move k 
                else if(sum < 0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return results;
    } 
};

int main() {
    solution solver;
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; 
    
    for (const auto& triplet : solver.threeSum(nums)) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }
    
    return 0;
}
