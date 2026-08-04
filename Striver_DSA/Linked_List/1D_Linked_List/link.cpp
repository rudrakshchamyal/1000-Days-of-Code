#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node( int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> arr){

    Node* head = new Node(arr[0]);
    Node* current = head;

    for( int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while( temp){
        if( temp-> data == val){
            return 1;
            break;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){

    vector<int> arr = {12, 5, 6, 9};
    Node *head = convertArr2LL(arr);
    
    Node* temp = head;
    while( temp != NULL){
        cout << temp->data << " ->";
        temp = temp->next;
    }
    cout << "null" << endl;

    cout << "Length of LL = " << lengthOfLL(head) << endl;

    cout << "Checking if 5 is present = " << checkIfPresent(head, 5) << endl;
}