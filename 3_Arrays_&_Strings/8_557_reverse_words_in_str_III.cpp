// given a string reverse the order of characters in each word while preserving the whitespaces and initial word order.

// ex : s = "let's take this " --> "s'tel ekat  siht"

// we use two pointers : start,end where end moves until it encounters a space when get a space we reverse the string (start,end -1) and start gets updated from end+1.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class sol
{
public:
    string reverse(string s)
    {
        int start = 0;
        for (int end = 0; end <= s.length(); end++)
        {
            // if end encounters last character of string or space we reverse the string
            if (end == s.length() || s[end] == ' ')
            {
                std::reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }
        return s;
    }
};
int main()
{
    sol obj;
    string s = "Let's take LeetCode contest";
    string result = obj.reverse(s);
    cout << result << "\n";
    return 0;
}
