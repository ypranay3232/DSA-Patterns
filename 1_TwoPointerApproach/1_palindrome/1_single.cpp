// given an sting and check if it is palindrome or not.

#include<iostream>
#include<string>
using namespace std;

// we create a function that accepts a string and check if a given string is palindrome or not
bool ispalindrome(string s){
    // create two pointers
    int left = 0;
    int right = s.length()-1;

    // loop until left < right 
    while(left<right){
        // now check if left (first digit) is equal to right(first digit) if not its not palindrome 
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;

    } 
    return true;
}

int main(){
    string s = "madam";
    if(ispalindrome(s)){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"not palindrome"<<endl;
    }

    return 0;

}