// Given a sting s, return true if string can be palindrome after deleting at most one character  from it. 

#include<iostream>
#include<string>

using namespace std;

class solution{
    public:
    //approach is pretty simple we write two functions one check if a palindrome or not another check the path of left and right.
    bool validpalindrome(string s){
        // now create two variables 
        int l =0;
        int r= s.length()-1;

        // until L and R not crossed each other
        while(l < r){
            // check if L equal to R. 
            if(s[l] != s[r]){
                // if not equal we check by skipping one character from bosh L, R path so we create a function that check for us 
                return ispalindrome(s, l+1, r) || ispalindrome(s,l,r-1);
            }
            // if both are equal that is a palindrome so we move both pointers
            l++;
            r--;
        }
        return true;
    } 
    private:
    bool ispalindrome(const string & s,int l, int r){
        while(l < r){
            // check if again having any mismatch 
            if(s[l] != s[r]){
                return false;//if got another mismatch its not a valid palindrome
            } 
            // else if no mismatch move pointers 
            l++;
            r--;
        }
        return true;
    }
};
int main(){
    solution obj;
    string s = "abca";
    cout << "Input: \"" << s << "\"\n";
    cout << "Output: " << (obj.validpalindrome(s) ? "true" : "false");
    return 0;
}