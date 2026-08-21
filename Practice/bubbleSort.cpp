#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    int x = n;

    for( int i = 0 ; i < n-1 ; i++){
        bool swapped = false;
        for( int j = 0 ; j < x-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        x--;
        if(!swapped){
            break;
        }
    }
}

void display(vector<int> arr){
    cout << "[ ";
    for( int i = 0 ; i < arr.size() - 1 ; i++){
        cout  << arr[i] << ", "; 
    }
    cout << arr[arr.size()-1] << "]";
}

int main(){

    vector<int> arr = {1,3,2,5,4,7,77,43,6,2};
    bubbleSort(arr);
    display(arr);

    return 0;
}