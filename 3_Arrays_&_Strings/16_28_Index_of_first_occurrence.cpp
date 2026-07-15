// given two strings : return first occurrence of str2 in str1. 
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // get length of two strs
        int n = haystack.length(), m = needle.length();
        if (m == 0) return 0;
        
        for (int i = 0; i <= n - m; i++) {
            // check substr
            if (haystack.substr(i, m) == needle) return i;
        }
        return -1;
    }
};

int main() {
    Solution solver;

    //  Needle is at the very beginning
    string haystack1 = "sadbutsad";
    string needle1 = "sad";
    cout << "Result -> Haystack: \"" << haystack1 << "\", Needle: \"" << needle1 << "\"" << endl;
    cout << "Result index: " << solver.strStr(haystack1, needle1) << "\n\n"; // Expected: 0
    return 0;
}
