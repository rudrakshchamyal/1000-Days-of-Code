#include<iostream>
#include<vector>

using namespace std;

int duplicate_Eelments(vector<int> arr){

    int n = arr.size();

    int i = 0;

    for( int j = 1 ; j < n ; j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1; 

}


int main(){

    int arr1[] = {1,1,2,2,3,3};
    cout << arr1[0];

    return 0;
}

