// you are given two integers array nums1 and num2 sort them into a single array. 
// The final sorted array should not be returned by the function, but instead be stored inside the array nums1

// to make this possible num1 has a length of m + n; m = nums1 n = nums2.

#include<iostream>
#include<vector>

using namespace std;

class sol{
    public:
    
    void mergearrays(vector<int>& num1, int m, vector<int> & num2, int n){
        int i = m -1;
        int j = n -1;
        // k is a pointer which points to end of num1 (m + n -1)
        int k = m + n -1;

        while (i >= 0 && j >=0)
        {
            // check if num1 current ele > num2 current ele then place the k (greater ele at last)
            
            if(num1[i] > num2[j]){
                num1[k] = num1[i];
                i--;
            }
            // if num1 current ele < num2 assign the k with j. 
            else{
                num1[k] = num2[j];
                j--;
            }
            k--;
        }
        // edge case : if num2 is having more elements than i. we copy them 
        while(j >= 0){
             num1[k] = num2[j];
             j--;
             k--;
        }
    }
};
int main(){
    sol obj;
    vector<int> num1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> num2 = {2,5,6};
    int n = 3;

    obj.mergearrays(num1,m,num2,n);

    cout<<"sorted array "<<endl;
    for(int x: num1){
        cout<<x<<" ";
    }
    cout<<endl;

    return 0;
}