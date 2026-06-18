#include<iostream>
using namespace std;

void findSum(int i , int sum){
    if(i < 0){
        cout << sum;
        return;
    }

    findSum( i - 1, sum +  i);

}

int main(){

    findSum(7, 0);
    cout << endl;

    return 0;
}