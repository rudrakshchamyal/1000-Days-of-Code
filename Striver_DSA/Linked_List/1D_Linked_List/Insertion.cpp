#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node( int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node *curr = head;

    for( int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void printLL(Node*& head){
    Node*temp = head;
    while(temp){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* insertionAthead(Node*& head, int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;

    return head;
}

Node* insertionAtLast(Node*& head, int val){
    Node* temp = new Node(val);
    Node* curr = head;
    while( curr->next != nullptr){
        
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = nullptr;

    return temp;
}

int countLL(Node*& head){
    Node* curr = head;
    int cnt = 1;
    while(curr){
        curr = curr->next;
        cnt++;
    }
    return cnt;
}

Node* insertionAtKthpos(Node*& head, int val, int k){

    if( k == 1){
        insertionAthead(head, val);
        return head;
    }

    Node*temp = new Node(val);
    Node* prev = nullptr;
    Node* curr = head;
    int cnt = 1;
    while(curr != nullptr && cnt <= k ){

        prev = curr;
        curr = curr->next;
        cnt++;
        
    }

    prev->next =temp;
    temp->next = curr;

    return temp;
}

int main(){
   vector<int> arr = {1,2,3,4,5};
   Node* head = convertArr2LL(arr);
   
   printLL(head);
   insertionAthead( head, 67);
   printLL(head);
   insertionAtLast(head, 444);
   printLL(head);
   insertionAtKthpos(head, 7, 7);
   printLL(head);

   return 0;
}