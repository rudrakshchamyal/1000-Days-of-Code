#include<bits/stdc++.h>
using namespace std;

int medianSearch(vector<int>& arr, int l, int r, int k){

    while(l < r){
        int indi = r-l+1;
        int index = l+(rand()%indi);
        int x = arr[index];

        int s1[10];
        int s2[10];
        int s3[10];

        int j = 0, n = 0 , m = 0;
        for (int i = l ; i < indi ; i++){
            if( arr[i] < x){
                s1[j] = arr[i];
                j++;
            }

            else if( arr[i] == x){
                s2[m] = arr[i];
                m++;
            }

            else{
                s3[n] = arr[i];
                n++;
            }
        }

        if(j > k){
            for(int y = 0 ; y < j ; y++){
                arr[l+y] = s1[y];
            }
            r = l+j-1;
        }

        else if( j+m > k){
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

