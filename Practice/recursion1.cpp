#include<iostream>
using namespace std;

void f(int i , int n){
    if( i > n){
        return;
    }

    cout << "Rudraksh" << endl;

    f(i+1, n);    
}

int main(){

    f(1,5);

    return 0;
}