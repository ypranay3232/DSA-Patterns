// A group of students are asked to stand in a non decreasing order, given an array of heights representing order of students heights. find out how many students are standing in wrong order.

// Approach : instead of sorting the whole array we can just cunt how many times a height appears, 
// so we create a frequency array (bucket of 101) because height in array is (1-100)
// compare current expected height with actual height in array using pointers


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class sol{
    public:
    int heightChecker(vector<int>& heights){
        vector<int> count(101,0);//a bucket with values 0 -101
        for(int x : heights){//loop the height array 
            count[x]++;
        }
        int mismatch = 0;
        int currentheight = 0;

        // compare actual height with expected height from bucket
        for(int i = 0;i<heights.size();i++){
            // find next available height that should be in this position 
            while (count[currentheight]==0)
            {
                currentheight++;
            }
            // if actual hight does match expected height  
            if(heights[i] != currentheight){
                mismatch++;
            }
            count[currentheight]--;   
        }
        return mismatch;
    }
};

int main(){
    sol obj;
    vector<int> heights = {1, 1, 4, 2, 1, 3};
    // Given 1,1,4,2,1,3 ==> when we sort ==> 1,1,1,2,3,4 : so 3 are in mismatch so we return 3

    cout << "Input Heights: [1, 1, 4, 2, 1, 3]" << endl;
    cout << "Expected Output: 3" << endl;
    
    int result = obj.heightChecker(heights);
    cout << "Code Output: " << result << endl;

    return 0;
}