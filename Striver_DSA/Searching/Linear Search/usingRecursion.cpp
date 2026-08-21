#include<bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int> arr, int val, int i = 0){
    if( i == arr.size() ) return -1;

    if( val == arr[i]){
        return i;
    }

    
    return LinearSearch(arr, val, i+1);
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout << LinearSearch(arr, 12);
}