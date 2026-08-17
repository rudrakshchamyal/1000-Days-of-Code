#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

void push(Node*& head, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = newNode;
        head->next = nullptr;
        return;
    }

    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = newNode;
    newNode->next = nullptr;

}

void pop(Node*& head){
    Node* current = head;
    if(head == nullptr){
        cout << "Empty Queue!" << endl;
        return;
    }

    head = head->next;
    delete current;

}

void printLL(Node*& head){

    Node* current = head;
    while(current->next != nullptr ){
        cout << current->data << " --> ";
        current = current->next;
    }
    cout << current->data << " --> " << "nullptr" << endl << endl;
}

void peek(Node*& head){
    if(head == nullptr){
        cout << "QUEUE is Empty!" << endl;
        return;
    }
    cout << head->data << endl;
}

bool isEmpty(Node*& head){
    if( head == nullptr){
        return true;
    }
    return false;
}

int main(){

    Node* head = nullptr;
    push(head, 10);
    push(head, 12);
    push(head, 14);
    printLL(head);

    pop(head);
    printLL(head);

    peek(head);
    cout << isEmpty(head);

    return 0;
}












