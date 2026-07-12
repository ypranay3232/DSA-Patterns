// given an 2D matrix with numbers, return the elements of matrix in a spiral path.we start at top left corner [0][0]. We move to the center of the matrix.

// so we need 4 pointers which traverse from left(top) to right and (top to bottom) and (bottom to left) and left to right

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // This vector will store final result sequence
        vector<int> ans;
        
        // If the matrix is empty, return the empty answer array immediately
        if (matrix.empty()) return ans;

        // Initialize our 4 boundaries
        int top = 0;                     // Row index for the topmost unvisited row
        int bottom = matrix.size() - 1;   // Row index for the bottommost unvisited row
        int left = 0;                    // Column index for the leftmost unvisited column
        int right = matrix[0].size() - 1; // Column index for the rightmost unvisited column

        // Loop continues until the boundaries cross each other
        while (top <= bottom && left <= right) {
            
            // 1. Move from LEFT to RIGHT along the current 'top' row
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            // We finished the top row, so push the top boundary down
            top++;

            // 2. Move from TOP to BOTTOM along the current 'right' column
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            // We finished the right column, so push the right boundary left
            right--;

            // 3. Move from RIGHT to LEFT along the current 'bottom' row
            // Condition check ensures we haven't already processed this row during 'top++'
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                // We finished the bottom row, so push the bottom boundary up
                bottom--;
            }

            // 4. Move from BOTTOM to TOP along the current 'left' column
            // Condition check ensures we haven't already processed this column during 'right--'
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                // We finished the left column, so push the left boundary right
                left++;
            }
        }
        
        // Return the fully populated spiral path
        return ans;
    }
};

int main() {
    // Creating a sample 3x4 grid for testing
    vector<vector<int>> matrix = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);

    // Print the output vector to check our spiral results
    cout << "Spiral Order: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
