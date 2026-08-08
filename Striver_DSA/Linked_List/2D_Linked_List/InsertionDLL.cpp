#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* convertArr2DLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* current = head;

    for( int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        current->next = temp;
        temp->prev = current;
        current = temp;
    }
    return head;
}

Node* insertBeforeHead(Node*& head, int val){
    Node* newNode = new Node(val);
    if( head == nullptr){
        head = newNode;
        return newNode;
    }

    newNode->next  = head;
    head->prev = newNode;
    head = newNode;

    return newNode;
}

Node* insertBeforeTail(Node*& head, int val){

    Node* newNode = new Node(val);
    Node* tail = head;

    if( head == nullptr){
        head = newNode;
        return newNode;
    }

    while(tail->next != nullptr){
        tail = tail->next;
    }

    if (tail->prev == nullptr) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode; 
        return newNode;
    }

    Node* prevNode = tail->prev;
    newNode->next = tail;
    tail->prev = newNode;

    prevNode->next = newNode;
    newNode->prev = prevNode;

    return newNode;

}



void printDLL(Node*& head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2DLL(arr);
    insertBeforeHead(head, 69);
    insertBeforeTail(head, 555);

    printDLL(head);
}

