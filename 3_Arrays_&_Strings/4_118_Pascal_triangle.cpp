// Given an integer numRows, return the first numRows
/*
Pascal Triangle : we take sum of two nodes and add it in between next two pointers.
                1
            1      1
        1 (1 + 1 = 2) 1
    1 (1 + 2) (2 + 1)    1
    1    3     3         1
1 (3 + 1) (3 + 3) (3+1)  1
1      4    6        4   1

problem asks you to return the first numRows of Pascal's Triangle.
In Pascal's Triangle, each number is the sum of the two numbers directly above it.

The first and last element of every row is always 1.
Every other element at index j in the current row is the sum of elements at index j-1
and j from the previous row.
If numRows = 5

     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]

*/

#include <iostream>
#include <vector>

using namespace std;

class sol
{

public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows);
        // loop the array
        for (int i = 0; i < numRows; i++)
        {
            // we set the current Row with 1 , 1
            triangle[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j)
            {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle;
    }
};
int main()
{
    sol obj;
    int numRows = 5;
    vector<vector<int>> result = obj.generate(numRows);
    cout << "Pascal's Triangle for " << numRows << " rows:\n\n";
    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}