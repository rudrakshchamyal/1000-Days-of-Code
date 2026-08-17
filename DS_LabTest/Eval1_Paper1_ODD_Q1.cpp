#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int id;
    string name;
    float salary;
    Node* next;

    Node( int id1, string name1, float salary1, Node* next1 = nullptr){
        id = id1;
        name = name1;
        salary = salary1;
        next = next1;
    }

};

Node* head = nullptr;

void append(Node*& head, int id1, string name1, float salary1){
    Node* newNode = new Node(id1, name1, salary1);

    if( head == nullptr){
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

void printLL(Node*& head){
    Node* temp = head;
    while(temp->next != nullptr){
        cout << "[" << temp->id << ", " << temp->name << ", " << temp->salary << "]" << " --> ";
        temp = temp->next;
    }
    cout << "[" << temp->id << ", " << temp->name << ", " << temp->salary << "]" << " --> " << "nullptr" << endl << endl;
}

bool checkSH(string str){
    int l = str.length();
    if(str[l-2] == 's' && str[l-1] == 'h'){
        return true;
    }
    return false;
}

void printEmployeeNameEndWithSH(Node*& head){
    cout << "Printing names ending with \'sh' -->" << endl;
    Node* current = head;
    while( current != nullptr){

        if(checkSH(current->name)){
            cout << current->name << endl;
        }
        current = current->next;
    }

}

void printEmployeeWithSameSalary(Node*& head){
    cout << "Print Name and Salary -->" << endl;
    Node* current1 = head;
    Node* current2 = head->next;
    while(current1->next){
        while(current2){
            if(current1->salary == current2->salary){
                cout << "Name = " <<  current2->name << ", Salary = " << current1->salary << endl;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
        current2 = current1->next;

    }
}

void swapData(Node*& Node1, Node*& Node2){

     int idx = Node1->id;
     string namex = Node1->name;
     float salaryx = Node1->salary;

     Node1->id = Node2->id;
     Node1->name = Node2->name;
     Node1->salary = Node2->salary;

     Node2->id = idx;
     Node2->name = namex;
     Node2->salary = salaryx;

}

void sortName(Node*& head){
    Node* current1 = head;
    Node* current2 = head->next;

    while(current1->next != nullptr){
        Node* alpha = current1;
        while(current2){
            if(current2->name < alpha->name){
                alpha = current2;
            }
            current2 = current2->next;
        }
        swapData(alpha, current1);
        current1 = current1->next;
        current2 = current1->next;
    }
}

void sortSalary(Node*& head){
    Node* current1 = head;
    Node* current2 = head->next;

    while(current1->next != nullptr){
        Node* minSalary = current1;
        while(current2){
            if(current2->salary < minSalary->salary){
                minSalary = current2;
            }
            current2 = current2->next;
        }
        swapData(minSalary, current1);
        current1 = current1->next;
        current2 = current1->next;
    }
}

int main(){

    Node* head = nullptr;
    append(head, 301, "Rudraksh", 30);
    append(head, 302, "Krish", 11);
    append(head, 277, "Hardik", 30);
    append(head, 278, "Komal", 24);
    append(head, 279, "Jayendra", 35);
    append(head, 280, "Vaibhav", 35);

    printLL(head);

    sortSalary(head);
    printLL(head);

    sortName(head);
    printLL(head);

    printEmployeeWithSameSalary(head);

    return 0;
}










