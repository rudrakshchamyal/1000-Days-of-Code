#include<iostream>
using namespace std;

int main(){

int n;
cout << "Enter total number of elements = ";
cin >> n;

int arr[n];
cout << "Enter elements for the array ==>";

for( int i = 0 ; i < n ; i++){
    cout << "Enter element" << i+1 <<" = ";
    cin >> arr[i];
}

int hash[13] = {0};
for(int i = 0 ; i < n ; i++){
    hash[arr[i]] += 1;
}

int q;
cout << "Enter the number of queries (q): ";
cin >> q;

while(q--){
    int number;
    cin >> number;

    cout << "Frequency of " << number <<" is: " << hash[number] << endl;
    }
    return 0;
}