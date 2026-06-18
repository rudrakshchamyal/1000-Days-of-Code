#include<iostream>
#include<map>
using namespace std;

int main(){

    int n;
    cout << "Enter total elements: ";
    cin >> n;

    int arr[n];

    map<int, int> mpp;
    for(int i = 0 ; i < n ; i++){

        cout << "Enter number" << i+1 << ": ";
        cin >> arr[i];
        
        mpp[arr[i]] += 1;
    }

    for(auto it : mpp){
        cout << it.first << " --> " << it.second << endl;
    }

    int q;
    cout << "Enter total queries: ";
    cin >> q;

    while(q--){

        int number;
        cout << "Enter number to check frequency: ";
        cin >> number;

        cout << "Frequency of" << number << " = " << mpp[number] << endl;

    }

    return 0;
}