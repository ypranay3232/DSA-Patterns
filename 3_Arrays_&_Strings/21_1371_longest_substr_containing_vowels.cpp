#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Solution {
    int findTheLongestSubstring(std::string s) {
        vector<int> m(32, -2); m[0] = -1;
        int mask = 0, res = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') 
                mask ^= 1 << (c == 'a' ? 0 : c == 'e' ? 1 : c == 'i' ? 2 : c == 'o' ? 3 : 4);
            if (m[mask] != -2) res = std::max(res, i - m[mask]);
            else m[mask] = i;
        }
        return res;
    }
};

int main() {
    Solution solver;
    string test = "eleetminicoworoep";
    cout << "Longest Substring Length: " << solver.findTheLongestSubstring(test) << std::endl;
    return 0;
}
