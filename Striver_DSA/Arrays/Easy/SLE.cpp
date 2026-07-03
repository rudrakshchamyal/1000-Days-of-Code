#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> arr = {1};
    int n = arr.size();

    int le = arr[0];
    int sle;

    if(n < 2){
        cout << "No Second Largest Element Exist!" << endl;
    }

    else{

        for( int i = 0 ; i < n ; i++){
            if( le < arr[i] ){
                sle = le;
                le = arr[i];
            }

            else if (arr[i] < le && arr[i] > sle) {
                sle = arr[i];
            }
        }

        cout << sle;
    }

    return 0;
}
