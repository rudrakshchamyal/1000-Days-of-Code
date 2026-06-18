#include<iostream>
using namespace std;

void f(int i , int sum){ // i = 0, sum = 6
    if(i < 1){
        cout << sum;
        return;
    }

    f(i-1, sum+i);
}

int main(){

    f(3,0);
    
    return 0;
}