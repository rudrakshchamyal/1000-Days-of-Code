#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& nums){
    int n = nums.size();
    for( int i = 0 ; i < n-1 ; i++){
        int minIndex = i;
        for( int j = i+1 ; j < n ; j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        if( i != minIndex){
            swap(nums[i], nums[minIndex]);
        }
    }
}

void printArr(vector<int> arr){
    cout << "[ ";
    for( int i = 0 ; i < arr.size() - 1 ; i++){
        cout  << arr[i] << ", "; 
    }
    cout << arr[arr.size()-1] << "]";
}

int main(){

    vector<int> arr = {1,4,3,2,5,6};

    selectionSort(arr);
    printArr(arr);

    return 0;
}