#include<bits/stdc++.h>
using namespace std;

class Queue{
public:

    int arr[100];
    int Front;
    int Rear;

    Queue(){
        Front = 0;
        Rear = 0;
    }

    void enqueue(int val){
        if(Rear == 100){
            cout << "Queue Overflow!" << endl;
            return;
        }
        arr[Rear] = val;
        Rear++;
    }

    void dequeue(){
        if(Front == Rear){
            cout << "Queue is empty!" << endl;
            return;
        }
        Front++;
    }

    void peek(){
        if(Front == Rear){
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[Front];
    }

    bool isEmpty(){
        if(Front == Rear){
            return true;
        }
        return false;
    }

    void displayQueue(){
        int i = Front;
        while(i < Rear){
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }

};

int main(){

    Queue q1;

    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);

    q1.displayQueue();

    q1.dequeue();
    q1.displayQueue();

    q1.peek();

    return 0;
}










