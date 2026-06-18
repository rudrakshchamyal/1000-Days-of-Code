#include<iostream>
using namespace std;

void f(int i){
    if(i < 1){
        return;
    }

    f(i-1);
    cout << i << endl;
}

int main(){

    f(6);

    return 0;
}