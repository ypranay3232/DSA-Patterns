// given an array, replace every elements in that array with greatest elements among to its right side. 

/*
given an array : [17,18,5,4,6,1]
first we pick 17 (its right side elements greatest is : 18)
then we pick 18 (its right side element greatest is : 6 )
then we pick 5 (its right side element greatest is : 6 )
then we pick 4 (its right side element greatest is : 6 )
then we pick 6 (its right side element greatest is : 1 )
then we pick 1 (its right side element greatest is : -1 because no other element exist so -1 )


NOTE : current element itself doesn't count as 'right'
*/

// Approach : scan the array from back to front and get the max val 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class sol{
    public:
    vector<int> ReplaceEleRight(vector<int>& arr){
        // variable to store max value
        int max_so_far = -1;

        // we loop the array from backwards instead of starting fro int i = 0, we start from end of array. the loop will run until array hit index 0 (start) and we decrement each position 
        for(int i = arr.size()-1; i>=0;i-- ){
            int current_val = arr[i];//we store current values of array in a current_val
            arr[i] = max_so_far; //we update current value with whatever is highest to its right
            max_so_far = max(max_so_far,current_val);//compare curr val and max val and get max values to be stored in max_so_far
        }
        return arr;
    }
};

int main(){
    sol obj;
    vector<int> arr = {17,18,5,4,6,1};

    obj.ReplaceEleRight(arr);

    // print the array 
    for(auto x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}