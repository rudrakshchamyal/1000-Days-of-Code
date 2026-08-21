#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* next;

    Node( int  data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }

};

void append( Node*& head, int val){

    Node* newNode= new Node(val);

    if( head == nullptr){
        head = newNode;
        head->next = head;
    }

    Node* temp = head;
    while( temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;

}

void displayLL(Node*& head){
    Node* current = head;
    do{
        cout << current->data << " --> ";
        current = current->next;
    }while(current != head);

    cout << "returns to head : " << current->data;
}

void clear(Node*& head){
    Node* current = head;
    while( current->next != head){
        current = current->next;
    }
    current->next = nullptr;

    current = head;
    while(current){
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int main(){

    Node* head = nullptr;
    
    append(head, 1);
    append(head, 2);
    append(head, 3);

    displayLL(head);

    return 0;
}

