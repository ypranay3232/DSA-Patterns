// given a input string reverse the order of words, separated by a space
// NOTE : string may contains multiple space between, returned string must have only one space between strings.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class sol
{

public:
    string ReverseWords(string s)
    {
        // reverse the string and idx --> tracks the write position
        reverse(s.begin(), s.end());
        int n = s.size();
        int idx = 0;

        // loop the array : start points to starting index (reversed string starting)
        for (int start = 0; start < n; start++)
        {
            // here we find the first valid word as beginning
            if (s[start] != ' ')
            {
                // if its not the first word insert a space
                if (idx != 0)
                    s[idx++] = ' ';

                // now create end pointer : to scan for where this word end.
                int end = start;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];

                // Flip this individual word back to its correct spelling direction
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                start = end;
            }
        }
        // Chop off any remaining stale characters at the end
        s.resize(idx);
        return s;
    }
};

int main()
{
    sol obj;
    string test1 = "  hello   world  ";
    cout << "Original: '" << test1 << "'\n";
    cout << "Reversed: '" << obj.ReverseWords(test1) << "'\n\n";

    return 0;
}