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

Node* convertArr2LL(vector<int> arr){
    Node*head = new Node(arr[0]);
    Node* current = head;

    for( int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

Node* deleteHead(Node*head){
    if(head == NULL ) return head;
    Node*temp = head;
    head = head->next;
    free(temp); // or write --> delete temp;

    return head;
}

int deleteTail(Node*head){

    if(head == NULL){
        return -1;
    }

    else if(head->next == NULL){
        int val = head->data;
        free(head);
        return val;
    }

    Node* tail = head;
    while(tail->next->next != nullptr){
        tail = tail->next; 
    }
    int val = tail->data;

    free(tail->next);
    return val;
}

void deleteKelement(Node* head, int k){

    if( k == 1){
        deleteHead(head);
    }

    else if(k > 1 && k < 5){
        int cnt = 1;
        Node* temp = head;

        while( cnt < k){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next);

    }

    else if( k == 5){
        deleteTail(head);
    }

    else{
        cout << "K is Out of bounds!" << endl;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head = convertArr2LL(arr);
    cout << deleteHead(head) << endl;
    cout << deleteTail(head) << endl;
    deleteKelement(head, 4);



    return 0;
}