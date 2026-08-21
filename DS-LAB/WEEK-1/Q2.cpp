/*Q2. Given an array of numbers, input one number from this array and find
if it’s next-greater-element exists to the right of this value in the array. If
yes, give the position, else print “Not found”. Use stacks to perform this
operation.
Example 1:
Input: arr[] = {1,4,2,5,0,6,7}
Input: element= 4
Output: 2 (element 5 is the first next-greater-element which exists to
the right of the given element in the array, and it is 2 positions far from
4).
Example 2:
Input: arr[] = {1,4,2,5,0,6,7}
Input: element= 2
Output: 1 (element 5 is the first next-greater-element which exists to the
right of the given element in the array, and it is 1 position far from 2).
Example 3:
Input: arr[] = {10,4,2,5,0,6,7}
Input: element= 7
Output: “Not found” (There are no element to the right of 7 in this
array)
Example 4:
Input: arr[] = {10,6,7,2,5,1,0,4}
Input: element= 7
Output: “Not found” (There are elements to the right of 7, but none of
them are greater than 7). 
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int nextGreaterPos( vector<int>& vec, int element){
    int n = vec.size();
    int index = 0;
    while(vec[index] != element){
        index++;
    }

    if( index == n-1){
        return -1;
    }

    stack<int> myStack;

    int i = index;

    while(element >= vec[i]){
        myStack.push(vec[i]);
        i++;
    }

    return myStack.size();
}

int main(){
    vector<int> v1 = {1,4,2,5,0,6,7};
    cout << nextGreaterPos(v1, 7);

    return 0;
}