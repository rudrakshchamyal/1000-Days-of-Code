#include<bits/stdc++.h>
using namespace std;

stack<int> myStack;

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

Node* reverseDLL(Node*& head, stack<int>& myStack){
    Node* temp  = head;
    while(temp != nullptr){
        myStack.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->data = myStack.top();
        myStack.pop();
        temp = temp->next;
    }
    return head;
}

void printDLL(Node*& head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2DLL(arr);

    printDLL(head);

    reverseDLL(head, myStack);
    printDLL(head);
}

