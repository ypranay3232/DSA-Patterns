// Given a string avoid numeric characters, special characters and white spaces etc, then convert them to lower case.

#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

class Solution{
    public:

    bool ispalindrome(string s){
        // first we create two pointers
        int left = 0;
        int right = s.length()-1;

        // check if Left < right, check if left contains alpha numeric characters if yes move  
        while(left < right){
            if(!isalnum(s[left])){
                left++;
            }else if(!isalnum(s[right])){
                right--;
            }
            else{
                // now check if both are equal after converting to lower case
                if(tolower(s[left]) != tolower(s[right]) ){
                    return false;
                }
                left ++;
                right --;
            }
        }
        return true;
    }

};


int main(){
    Solution obj;
    string s = "A man, a plan, a canal Panama";

    if(obj.ispalindrome(s)){
        cout<<s<<": is a valid palindrome"<<endl;
    }else{
        cout<<s<<": is not a valid palindrome"<<endl;
    }
    return 0;
}