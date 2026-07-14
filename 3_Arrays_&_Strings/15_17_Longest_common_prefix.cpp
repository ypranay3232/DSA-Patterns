/*Given a longest common prefix means : finding longest string of characters.

Rules:

Must start at index 0: It is a prefix, so characters must match from the beginning.

Must be common to ALL: If even one string misses a character or ends early, the prefix stops there.

Empty cases: If the list is empty, or if there is no common beginning character, the result is an empty string "".

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// first we Scanning array
string longestCommonPrefixVertical(vector<string>& strs) {
    if (strs.empty()) return "";
    
    // Loop through each character of the first string
    for (int i = 0; i < strs[0].length(); ++i) {
        char c = strs[0][i];
        
        // Compare this character with the same position in all other strings
        for (int j = 1; j < strs.size(); ++j) {
            // Stop if the current string is shorter than index 'i' or if characters mismatch
            if (i == strs[j].length() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

int main() {
    vector<string> res = {"flower", "flow", "flight"};
    cout << "Output : \"" << longestCommonPrefixVertical(res) << "\"\n"; // Expected: "fl"

    return 0;
}
