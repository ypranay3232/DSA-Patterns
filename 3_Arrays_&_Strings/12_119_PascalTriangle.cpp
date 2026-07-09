// given an zero indexed array return the specific row of the pascal scale.

#include <iostream>
#include <vector>

using namespace std;

class sol
{
public:
    vector<int> getRow(int rowIndex)
    {
        // first we create a array filled with 1s
        vector<int> row(rowIndex + 1, 1);

        // now build the triangle by updating elements from back to front
        for (int i = 1; i < rowIndex; i++)
        {
            for (int j = i; j > 0; j--)
            {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};

int main()
{
    sol obj;
    int target_row = 3;

    vector<int> result = obj.getRow(target_row);
    std::cout << "Pascal's Triangle Row " << target_row << ": [";
    std::string separator = "";
    for (int num : result)
    {
        std::cout << separator << num;
        separator = ", "; 
    }
    std::cout << "]" << std::endl;
    return 0;
}