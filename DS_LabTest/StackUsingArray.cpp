#include<bits/stdc++.h>
using namespace std;

class Stack{
public:

    int arr[100];
    int val;
    int top;

    Stack(){
        top = -1;
    }

    void push(int val){
        if(top >= 99){
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop(){
        if(top == -1 ){
            cout << "Stack is empty!" << endl;
            return;
        }
        top--;
    }

    void peek(){
        if(top == -1){
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << arr[top] << endl;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    void displayStack(){
        int i = top;
        while(i >= 0){
            cout << arr[i] << " ";
            i--;
        }
        cout << endl;
    }

};

int main(){

    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.displayStack();

    return 0;
}












