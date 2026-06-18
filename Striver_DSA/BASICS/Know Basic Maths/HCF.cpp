#include<iostream>
using namespace std;

int main(){
    
    int num1, num2;

    cout << "Enter number1 = ";
    cin >> num1;

    cout << "Enter number2 = ";
    cin >> num2;

    int HCF = 1;

    for( int i = 1 ; i <= min(num1,num2) ; i++){
        if( num1 % i == 0 && num2 % i == 0 && i > HCF){
            HCF = i;
        }

    }

    cout << "Highest Common Factor of " << num1 << " and " << num2 << " = " << HCF << endl;

    return 0;
}