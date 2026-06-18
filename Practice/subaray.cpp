#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v = {1,2,3,4};
    int n = v.size();

    for( int i = 0 ; i < n ; i++){
        for( int j = i ; j < n ; j++ ){
           for( int k = i ; k <= j ; k++){
            cout << v[k] << ", ";
           }
           cout << "\t";
        }
        cout << endl;
    }



    return 0;
}