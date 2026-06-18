#include<iostream>
using namespace std;

int findHCF(int a, int b){
    if( b == 0){
        return a;
    }
    return findHCF(b,a % b);
}



int main(){

    cout << findHCF(6, 9);

    return 0;
}