#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> v){
    for( int i = 0 ; i < v.size() ; i++){
        cout << v[i] << endl;
    }
}

void reverse(int i, int j, vector<int> &v){
    if (i >= j){
        return;
    }

    swap( v[i], v[j] );

    return reverse(i+1 , j-1 , v );
}

int main(){

    vector<int> v = {1, 3, 5, 7, 9};
    cout << "ORIGINAL VECTOR = " << endl;
    print(v);

    cout << "REVERSED VECTOR = " << endl;
    reverse(0, v.size() - 1, v);
    print(v);

    return 0;
}