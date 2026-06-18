#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int num;
    cout << "Enter a number = ";
    cin >> num;
    int temp = num, sum = 0, x = 0;
    int count = 0;

    temp = num;
    while(temp != 0){
        temp /= 10;
        count++;
    }

    temp = num;
    while(temp != 0){
        x = temp % 10;
        sum += pow(x,count);
        temp /= 10;
    }

    if( sum == num){
        cout << "YES";
    }

    else{
        cout << "NO";
    }

    return 0;
}