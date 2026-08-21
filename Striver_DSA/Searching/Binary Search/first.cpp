#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int val){
    int low = 0;
    int high = arr.size() - 1;
    
    while(low <= high){ 
        int mid = low + (high - low)/2;
        if( arr[mid] == val){
            return mid;
        }

        else if( arr[mid] < val){
            low = mid + 1;            
        }

        else if(arr[mid] > val){
            
            high = mid - 1;
        }
   
    }
    return -1;
}

int main(){
    vector<int> arr = { 1,2,3,4,5,6,7,8,9,10};
    cout << BinarySearch(arr, 6);

    return 0;
}