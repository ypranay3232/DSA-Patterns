// Given an array of fixed length and we have to duplicate the zeros in the array. we cant use extra space. 
//And shifting the remaining elements to the right.

// ex: [1,0,2,3,4,5] ==> we duplicate 0s so : [1,0,0,2,3,4,5]

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class sol{
    public:
    // first we create a function that take an array by reference so changes are reflected directly
    void duplicatezeros(vector<int>& arr){
        // then we create a queue named helper
        queue<int> helper;
        // now we loop from left to right in array, so we use reference of num to array so we can make changes to num it reflects in arr
        for(int &num : arr){
            // now take the array and push it into queue
            helper.push(num);
            // duplicate logic : if we see a zero in loop we duplicate 0 and push it to queue 
            if(num == 0){
                helper.push(0);
            }
            // so we check the front number and we pop it once we get next element. because queue is FIFO : when we insert new elements (after duplicating 0's) we have to remove the remaining elements which are inserted at front because array space is constant so we do as : 
            num = helper.front(); //point to front of queue if its not duplicate
            helper.pop();//remove it
        }
    }
};

int main(){
    sol obj;
    vector<int> arr = {1,0,2,3,0,4,5,0};

    obj.duplicatezeros(arr);
    for(auto num : arr){
        cout<<num<<" ";//we get only upto 4 because array size is constant
    }
    cout<<endl;

    return 0;
}