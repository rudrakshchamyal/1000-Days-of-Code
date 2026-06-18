#include<iostream>
using namespace std;

void print(int i){
    if(i < 1){
        return;
    }

    cout << i << endl;
    print(i-1);
}

int main(){

    print(8);

    return 0;
}