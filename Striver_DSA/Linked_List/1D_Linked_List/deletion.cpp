#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

Node* convertArr2LL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (size_t i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        current->next = temp;
        current = temp;
    }
    return head;
}

// Pass head by reference so deletions at head reflect outside the function
Node* deleteHead(Node*& head) {
    if (head == nullptr) return nullptr;
    
    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

int deleteTail(Node*& head) {
    if (head == nullptr) return -1;

    // Single node case
    if (head->next == nullptr) {
        int val = head->data;
        delete head;
        head = nullptr;
        return val;
    }

    // Traverse to second-to-last node
    Node* tail = head;
    while (tail->next->next != nullptr) {
        tail = tail->next;
    }

    int val = tail->next->data;
    delete tail->next;
    tail->next = nullptr; // Clear dangling pointer

    return val;
}

void deleteKelement( Node*& head, int k){
    if( k <= 0 && head != nullptr ){
        deleteHead(head);
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 1;

    while( temp != nullptr && cnt < k){
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    prev->next = temp->next;
    delete temp;
}

void delete_by_value(Node*& head, int val){
    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr && temp->data != val){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    delete temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);

    cout << "Original List: ";
    printList(head);

    deleteHead(head);
    cout << "After deleting head: ";
    printList(head);

    cout << "Deleted Tail Value: " << deleteTail(head) << endl;
    cout << "After deleting tail: ";
    printList(head);

    deleteKelement(head, 2); // Deletes element at 1-based position 2
    cout << "After deleting position 2: ";
    printList(head);

    return 0;
}