#include <iostream>       
#include <vector>        
#include <unordered_set> 

class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> s(nums1.begin(), nums1.end());
        std::vector<int> res; // Initialize a vector container to hold our final unique intersection elements
        
        // Loop through each integer present inside the second array
        for (int x : nums2) {
            // Check if the current element from nums2 exists inside our nums1 hash set
            if (s.erase(x)) { 
                res.push_back(x); // If found, add it to results; s.erase(x) returns 1 and prevents future duplicates
            }
        }
        return res; 
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {1, 2, 2, 1}; 
    std::vector<int> nums2 = {2, 2};    

    // call the intersection algorithm and capture the resulting vector
    std::vector<int> result = solver.intersection(nums1, nums2);

    std::cout << "Intersection: "; 
    
    // Loop through the output results vector and print each integer element
    for (int num : result) {
        std::cout << num << " "; 
    }
    std::cout << std::endl; 

    return 0; 
}
