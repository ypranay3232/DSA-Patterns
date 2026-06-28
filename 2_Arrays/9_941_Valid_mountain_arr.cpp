// given an array return true if its a valid mountain array.

// A valid mountain array has 3 conditions to satisfy :
// 1) length > 3, 2)should be in increasing order, 3) strictly in decreasing order after peak.

// Observation is pretty simple : we dont need to find the max element just keep climbing until the array order is in increasing order, when we encounter decreasing order that is peak.

#include <iostream>
#include <vector>

using namespace std;

class sol
{
public:
    bool validMountain(vector<int> &arr)
    {
        int n = arr.size();
        // base case : if n < 3 break
        if (n < 3)
            return false;

        // climb up until
        int i = 0;
        while (i + 1 < n && arr[i] < arr[i + 1])
        {
            i++;
        }
        // Peak cannot be first or last
        if (i == 0 || i == n - 1)
            return false;

        // Go down
        while (i + 1 < n && arr[i] > arr[i + 1])
        {
            i++;
        }

        return i == n - 1;
    }
};

int main()
{
    sol obj;
    vector<int> arr = {0, 3, 2, 1};

    if (obj.validMountain(arr))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}