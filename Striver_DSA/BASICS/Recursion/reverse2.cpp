#include<iostream>
#include<vector>

using namespace std;

// Fixed: Specified the type 'vector<int>&' and updated base case
void print(int i, const vector<int> &v){
    if(i >= v.size()){ // Stops exactly when i goes out of bounds
        return;
    }
    cout << v[i] << " ";
    print(i + 1, v);
}

// Fixed: Used v.size() dynamically inside the function
void reverse(int i, vector<int> &v){
    int n = v.size(); 

    if( i >= n - i - 1 ){ // Correct single-pointer midpoint check
        return;
    }

    swap(v[i], v[n - i - 1]);

    reverse(i + 1, v);
}

int main(){
    vector<int> v = {1, 2, 34, 5, 3, 23, 3};
    
    reverse(0, v);
    
    cout << "REVERSED VECTOR: ";
    print(0, v);
    cout << endl;

    return 0;
}