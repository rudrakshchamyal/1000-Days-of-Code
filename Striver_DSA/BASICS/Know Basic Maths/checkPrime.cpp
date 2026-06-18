#include<iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number = ";
    cin >> num;

    bool isPrime = false;

    for( int i = 2 ; i < num ; i++){
        if( num % i == 0){
            isPrime = true;
            break;
        }
    }

    if(!isPrime){
        cout << "It is a PRIME Number!";
    }

    else{
        cout << "IT is NOT a PRIME Number!";
    }

    return 0;
}