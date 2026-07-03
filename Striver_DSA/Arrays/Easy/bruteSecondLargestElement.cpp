#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    vector<int> v = {2,3,1,2,3,4,5,5,3,3,5,7,3,5,12};
    sort( v.begin(), v.end() );

    int sle = -1;
    int n = v.size();

    if( n < 2){
        cout << "Second Largest Element Does NOT Exist!" << endl;
    }

    for( int i = n - 2 ; i >= 0 ; i--){
        if( v[i] != v[i-1]){
            sle = v[i];
            break;
        }
    }

    cout << sle;

    return 0;
}