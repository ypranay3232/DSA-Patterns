// write a function that reverse an string, The input string is given as an array of characters, so modify the string with 0(1) memory. meaning use no extra space.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:

    void reverseString(vector<char>& s){
        // first we create two pointer 
        int left = 0;
        int right = s.size()-1; //for string we use length() for arrays we use size()

        // now check if left < right if yes then swap both and increment pointers
        while(left < right ){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main(){
    Solution obj;
    vector<char> s = {'h','e','l','l','o'};
    obj.reverseString(s);
    cout<<"Reversed string"<<endl;
    for(auto x: s){ //use auto if you forgot and mention another datatype like me. 
        cout<<x;
    }
    cout<<endl;
    
    return 0;
}