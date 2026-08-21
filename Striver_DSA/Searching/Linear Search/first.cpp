#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(vector<int> arr, int val){
    int x = val;
    for( int i = 0 ; i < arr.size() ; i++){
        if(arr[i] == x){
            return true;
        }        
    }

    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    cout << LinearSearch(arr, 4);

    return 0;
}