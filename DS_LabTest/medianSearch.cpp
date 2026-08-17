#include<bits/stdc++.h>
using namespace std;


int medianSearch(vector<int> arr, int l, int r, int k){

    while( l < r){

        int indi = r-l+1;
        int index = l + (rand()%indi);
        int x = arr[index];

        vector<int> s1;
        vector<int> s2;
        vector<int> s3;

        for( int i = l ; i <= r ; i++){
            if(arr[i] < x){
                s1.push_back(arr[i]);
            }

            else if( arr[i] == x){
                s2.push_back(arr[i]);
            }

            else{
                s3.push_back(arr[i]);
            }
        }
        int j = s1.size();
        int m = s2.size();
        int n = s3.size();

        if(j > k){
            for( int y = 0 ; y < j ; y++){
                arr[l+y] = s1[y];
            }
            r = l+j-1;
        }

        else if( m+j >= k+1 ){
            return x;
        }

        else{
            for( int y = 0 ; y < n ; y++){
                arr[l+y] = s3[y];
            }
            r = l+n-1;
            k = k-j-m;
        }

    }
    return arr[l];
}

int main(){

    vector<int> a = {1,3,4,2,5,73,64,34,46,62,45};
    cout << medianSearch(a, 0, a.size()-1, 4);

    return 0;
}









