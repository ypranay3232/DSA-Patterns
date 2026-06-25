// Leetcode 246 : Strobogrammatic number : given a number and asked to determine if it looks exactly same when rotated 180 degrees.

// The rotations can be applied to only certain digits :
/*
0 --> 0
1 --> 1
6 --> 9
8 --> 8
9 --> 6

(2,3,4,5,7) becomes invalid upon rotation.
*/

// Approach : instead of rotating entire string in memory (which is a waste of space) we use two pointers to check from outside.

#include <iostream>
#include<vector>
#include <string>
using namespace std;

class solution
{

public:
    bool isStrobogrammatic(string num)
    {
        // first we create a lookup array for ASCI characters
        // then mark all characters with 0.
        char Lookup[256] = {0};

        // now we define valid rotations
        Lookup['0'] = '0';
        Lookup['1'] = '1';
        Lookup['6'] = '9';
        Lookup['8'] = '8';
        Lookup['9'] = '6';

        // initialize two pointers
        int left = 0;
        int right = num.length() - 1;

        // now we scan left to right
        while (left <= right)
        {
            char leftchar = num[left];
            char rightchar = num[right];

            // check if left is valid and its upside down version matches rightchar. if left is 0 or != rightchar(upside down version != original) we return false
            if (Lookup[leftchar] == 0 || Lookup[leftchar] != rightchar)
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main(){
    solution obj;
    string num = "69";

    bool result = obj.isStrobogrammatic(num);
    cout<<boolalpha<<result<<endl;

    return 0;
}