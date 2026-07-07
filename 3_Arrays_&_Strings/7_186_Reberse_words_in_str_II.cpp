// Given an character arrays, reverse the order of words. must be solved with O(1) without using extra space.

// ex : s = ["t","h","e","s","k","y","i","s","b","l","u","e"].

// the approach is first we reverse the entire string then we reverse the string characters.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class sol
{
public:
    void reverseArray(vector<char> &s)
    {
        int n = s.size();
        if (n == 0)
            return;

        // reverse the string
        reverse(s.begin(), s.end());

        // now we reverse the words individually
        int start = 0;
        for (int end = 0; end <= n; end++)
        {
            // check if end == size or if we encountered any space we have finished a word so revers that reversed word so we get valid word.

            if (end == s.size() || s[end] == ' ')
            {
                // Reverse the current word only (from start up to, but not including, the space at 'end')
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
    }
};

int main()
{
    sol obj;

    vector<char> s = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};

    obj.reverseArray(s);

    for (char c : s)
        cout << c << " ";
    cout << endl;

    return 0;
}