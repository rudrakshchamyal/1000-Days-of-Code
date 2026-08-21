#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int>& arr, int val,  int low, int high ){

    if(low > high){
        return -1;
    }
    
    int mid = low + (high - low)/2;

    if(arr[mid] == val){
        return mid;
    }

    if(arr[mid] < val){
        return BinarySearch(arr, val, mid+1,high);
    }

    return BinarySearch(arr, val, low, mid-1);

}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    cout << "Result: " << BinarySearch(arr, 23, 0, arr.size() - 1) << endl;
    return 0;
}