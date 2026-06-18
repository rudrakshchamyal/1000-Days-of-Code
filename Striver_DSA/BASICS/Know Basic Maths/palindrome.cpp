#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number = ";
    cin >> n;
    
    int originalNum = n;
    int revNum = 0, ld = 0;

    if (n < 0 || (n % 10 == 0 && n != 0)) {
        cout << "Number is NOT a palindrome!" << endl;
    } 
    else {
        while (n > revNum) {
            ld = n % 10;
            revNum = (revNum * 10) + ld;
            n /= 10; 
        }

        if (revNum == n || revNum / 10 == n) {
            cout << "Number is a palindrome!" << endl;
        } 
        else {
            cout << "Number is NOT a palindrome!" << endl;
        }
    }

    return 0;
}