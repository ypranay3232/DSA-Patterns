// write a function that reverse a string. The input string is given as an array of characters s. Must be done by modifying array with O(1)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class sol{

    public:
    void ReverseString(vector<char> & s){
        // just loop the array by two pointers : divided for loop into 3 parts (creating 2 pointers, condition (l<r), increment and decrement)
        for(int l = 0, r =s.size()-1; l<r;l++,r-- ){
            // swap l with r. 
            swap(s[l],s[r]);
        }
    }
};

int main(){
    sol obj;
    vector<char> s = {'h','e','l','l','o'};


    obj.ReverseString(s);
    for(char x : s) cout<<x<<" ";
    
    return 0;
}