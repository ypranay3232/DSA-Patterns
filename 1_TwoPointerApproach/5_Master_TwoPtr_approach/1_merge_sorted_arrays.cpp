// here we are given two arrays sorted in non decreasing order(ascending). merge num1 and num2 into single array sorted in non decreasing order.

// But the catch is you cannot create a new array rather you have to modify the array num1 so that it holds final merged result. so the num1 should be M + N size (i.e. should be double size) so we can later store the total results of num1, num2 inside it.

// the approach is pretty simple we place the largest elements at the end of num1 and smallest to left side and we update it. so we get sorted array.

#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
    void MergeSortedArrays(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // now we create two pointers which points to nums1, nums2
        int i = m - 1;
        int j = n - 1;
        // now we create another variable k which points to total nums1 + nums2 last index.
        int k = m + n - 1;

        // now compare both the elements from back to front and place them in descending order
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            { // if i > j then assign (k = i) then move
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                // assign k = j and decrement j
                nums1[k] = nums2[j];
                j--;
            }
            // now move the pointer k
            k--;
        }
        // case : we have to handle the case if num2 is having remaining elements (i.e more than nums1 copy them)
        while (j >= 0)
        {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    solution obj;
    obj.MergeSortedArrays(nums1, m, nums2, n);
    cout << "After merge, nums1 contains:  ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}