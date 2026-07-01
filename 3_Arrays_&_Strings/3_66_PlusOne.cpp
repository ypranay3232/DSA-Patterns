// given an array where current element nums[i] is a single digit from 0 - 9, The digits are ordered from left to right.

// we have to increment the largest integer by 1 and return the resulting array.
// When you add 1 to the last digit, it might cause a "carry" to ripple to the left (ex:9 + 1 = 10)

// Approach is very simple : we loop an array from backside and add + 1 to it if its < 9 (bcz if is 9 it will cause carry)
// else if (the number is 9 we add +1 to it. and it will become 10, so we assign it as 0 and move 1 as carry to next value)

#include <iostream>
#include <vector>

using namespace std;

class sol
{
public:
    vector<int> PlusOne(vector<int> &Digits)
    {
        // loop the array from backside until it hits 0(starting index) we decrement
        for (int i = Digits.size() - 1; i >= 0; i--)
        {
            // check if current digit < 8
            if (Digits[i] < 9)
            {
                Digits[i]++; // add + 1 to it
                return Digits;
            }
            // when current ele is 9 we get carry and val = 10 so we take 0.and push that carry to next value
            Digits[i] = 0;
        }
        Digits.insert(Digits.begin(), 1);
        return Digits;
    }
};

int main()
{
    sol obj;
    vector<int> Digits = {1, 5, 7};

    obj.PlusOne(Digits);

    for (int x : Digits)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}