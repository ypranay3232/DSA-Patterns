#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // first we create a bitmask for the allowed characters.
        // Since there are only 26 lowercase letters, we can fit this into a 32-bit integer.
        int allowed_mask = 0;
        for (char c : allowed) {
            // C' - 'a' gives a 0-indexed position (e.g., 'a'->0, 'b'->1, 'z'->25).
            // '1 << pos' shifts the bit '1' left by that position.
            // '|=' (bitwise OR) sets that specific bit to 1 in our mask.
            allowed_mask |= (1 << (c - 'a'));
        }
        
        int consistent_count = 0;
        
        // now Check each word in the list
        for (const string& word : words) {
            bool is_consistent = true;
            
            for (char c : word) {
                // Check if the bit for the current character is NOT set in the allowed_mask.
                // If the bitwise AND returns 0, it means the character is not allowed.
                if (!(allowed_mask & (1 << (c - 'a')))) {
                    is_consistent = false;
                    break; // Stop checking this word early (optimization)
                }
            }
            
            // If the loop finished without breaking, the word is consistent
            if (is_consistent) {
                consistent_count++;
            }
        }
        
        return consistent_count;
    }
};

int main() {
    Solution solution;

    string allowed1 = "ab";
    vector<string> words1 = {"ad", "bd", "aaab", "baa", "badab"};
    // Expected output: 2 ("aaab" and "baa" are consistent)
    cout << "Output: " << solution.countConsistentStrings(allowed1, words1) << endl;
    return 0;
}