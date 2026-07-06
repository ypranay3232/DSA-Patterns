// reverse a string using stack. The stack uses LIFO approach (we push characters from left to right so the last character ends up at top) so by poping elements we get reverse order

#include<iostream>
#include<stack>
#include<string>

using namespace std;

string reverseString(string str){
    stack<char> st;

    // first we push the characters into stack 
    for(char ch: str){
        st.push(ch);
    }

    // now we pop these : 
    for(int i = 0; i< str.length();i++){
        str[i] = st.top();//we start from top (first element LIFO--> insertion = Hello -->olleh) 
        st.pop();
    }
    return str;
}

int main(){
    string str = "hello";
    string reversed = reverseString(str);

    cout<<"reversed String : "<<reversed<<endl;
    return 0;
}