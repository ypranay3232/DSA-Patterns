// pair sum in sorted array : given an array and target find the number which sum up to target

#include <iostream>
#include <vector>
using namespace std;

void pairsum(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    bool found = false;

    while (left < right)
    {
        // try to sum values
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            cout << "Pair found: " << arr[left] << " and " << arr[right] << endl;
            found = true;
            left++;
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            // when sum > caret
            right--;
        }
    }

    if (!found)
    {
        cout << "No pair found that sums to " << target << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 7;
    pairsum(arr, target);
    return 0;
}