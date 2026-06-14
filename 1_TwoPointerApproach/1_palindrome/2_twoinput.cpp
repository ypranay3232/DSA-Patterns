// given two inputs and check if the given palindrome is valid or not
#include<iostream>
#include<string>
using namespace std;

bool ispalindrome(string s1,string s2){
    
    // simple if s1 and s2 are not at same length it cant be a palindrome
    if(s1.length() != s2.length()){
    return false;
  }

  int i = 0;//abc (a)
  int j = s2.length() -1;//cba (a)
  
  while(i< s1.length()){ //if i (a) < abc 
    if(s1[i] != s2[j]){
        return false;
    }
    i++;
    j--;
  }
  return true;
}

int main(){
    string s1 = "abc";
    string s2 = "cba";

    if(ispalindrome(s1,s2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}