//Problem Statement: Given an integer N return the reverse of the given number.
//Note: If a number has trailing zeros, then its reverse will not include them. For e.g , reverse of 10400 will be 401 instead of 00401.

#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int n, revNum = 0, lastDigit = 0;
    cout << "Enter a number = ";
    cin >> n;

    while(n != 0){

        lastDigit = n % 10;
        revNum = (10*revNum) + lastDigit;
        n /= 10;

    }

    cout << "Reverse Number = " << revNum;
    return 0;
}