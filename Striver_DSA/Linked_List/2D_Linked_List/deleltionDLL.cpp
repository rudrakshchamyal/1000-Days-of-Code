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

Node* deleteHead(Node*& head){
    if(head == nullptr) return nullptr;
    Node* temp = head; 
    head = head->next;

    if( head != nullptr){
        head->prev = nullptr;
    }

    delete temp;

    return head;
}

Node* deleteTail(Node*& head){
    if(head == nullptr) return nullptr;

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while( temp->next != nullptr){
        
        temp = temp->next;
    }
    Node* newNode = temp->prev;
    newNode->next = nullptr;
    
    delete temp;
    return head;
}

Node* deleteAtKpos(Node*& head, int pos) {
    // Edge case: empty list or invalid position
    if (head == nullptr || pos < 1) return head;

    Node* temp = head;
    int cnt = 1;

    // Traverse to the node at position `pos`
    while (temp != nullptr && cnt < pos) {
        temp = temp->next;
        cnt++;
    }

    // Case 1: `pos` is greater than the total number of nodes
    if (temp == nullptr) return head;

    // Case 2: Deleting the head node (pos = 1)
    if (temp == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }

    // Case 3: Deleting a middle or tail node
    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    if (prevNode != nullptr) {
        prevNode->next = nextNode;
    }
    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }

    delete temp;
    return head;
}

Node* deleteGivenNode( Node*& GivenNode){  //GivenNode cant be head!

    if(GivenNode->next == nullptr){
        Node* prevNode = GivenNode->prev;
        prevNode->next = nullptr;
        delete GivenNode;
        return prevNode;
    }

    Node* prevNode = GivenNode->prev;
    Node* nextNode = GivenNode->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete GivenNode;
    return prevNode;
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
    vector<int> arr = { 1,2,3,4,5};
    Node* head = convertArr2DLL(arr);
    deleteAtKpos(head, 3);    

    printDLL(head);
}

