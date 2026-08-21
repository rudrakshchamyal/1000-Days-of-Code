#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int val, int low = 0, int high = 9){

    if( low > high) return -1;

    int mid = low + (high-low)/2;

    if( arr[mid] == val){
        return mid;
    }

    else if( arr[mid] < val){
        low = mid + 1;
    }

    else if( arr[mid] > val){
        high = mid - 1;
    }

    return BinarySearch(arr, val, low, high);    
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    cout << BinarySearch(arr, 4);

    return 0;
}