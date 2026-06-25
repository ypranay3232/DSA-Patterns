// subsequence : letters of str1 appears inside str2 in same order and relation 
// ex: str1 = doggy str2 = dog (with same order)

// 2486 : append characters to make string subsequence. 
// Here we are given two strings containing only lowercase letters. 
// find how many are the min no of letters that should be added to str1 so that str2 becomes subsequence of str1.


/*
Example str1= "abc" and str2 = "a"
Let's look for str2 inside str1
We look for a: Found it immediately at the start of "**a**bc".
str2 is already completely matched
Answer: We need to add 0 characters.

*/

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class solution{

    public:
    int appendchar(string str1,string str2){
        // first we create two pointers for string 1,2 
        int i = 0; int j = 0;
        int str1_len = str1.length();
        int str2_len = str2.length();

        // until str1 ptr (i) < length and j < its length
        while(i < str1_len && j < str2_len ){
            // check the string characters if both match move st2 forward, because we check str2 with str1
            if(str1[i] == str2[j]){
                j++;
            }
            // else move str1 
            i++;
        }
        // charcters left unmatched in str2 must be appended to str1.
        return str2_len - j;
    }
};

int main(){
    solution obj;
    string str1 = "coaching";
    string str2 = "coding";
    int result = obj.appendchar(str1,str2);
    
    cout<<str1<<" "<<str2<<endl;
    cout<<"characters to append "<<result;

    return 0;
}