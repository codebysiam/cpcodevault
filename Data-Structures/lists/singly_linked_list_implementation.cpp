#include <bits/stdc++.h>
using namespace std;

/* -------------------- Singly Linked List Implementation -------------------- */
/*
    Implemented a singly linked list from scratch using pointers and
    object-oriented programming (OOP) concepts.
*/

class Node{
    public:
        int data;
        Node* next = nullptr;
    Node(int x){
        data = x;
    }
};

class LinkedList{
    private:
        Node* head = nullptr;
    public:
    ~LinkedList(){
        while(head != nullptr){
            pop_front();
        }
    }
    void push_front(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void push_back(int x){
        if(head == nullptr){
            push_front(x);
            return;
        }
        Node* newNode = new Node(x);
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
    void pop_front(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void pop_back(){
        if(head == nullptr) return;
        if(head->next == nullptr){
            pop_front();
            return;
        }
        Node* current = head;
        while(current->next->next != nullptr){
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    void insert(int index, int x){
        if(index < 0) return;
        if(index == 0){
            push_front(x);
            return;
        }
        Node* current = head;
        for(int i = 0; i < index - 1 && current != nullptr; i++){
            current = current->next;
        }
        if(current == nullptr) return;
        
        Node* newNode = new Node(x);
        newNode->next = current->next;
        current->next = newNode;
    }
    void remove(int index){
        if(index < 0) return;
        if(index == 0){
            pop_front();
            return;
        }
        Node* current = head;
        for(int i = 0; i < index - 1 && current != nullptr; i++){
            current = current->next;
        }
        if(current == nullptr || current->next == nullptr){
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    bool find(int x){
        if(head == nullptr) return false;
        Node* current = head;
        while(current != nullptr){
            if(current->data == x) return true;
            current = current->next;
        }
        return false;
    }
    int front(){
        if(head == nullptr) throw length_error("List is empty.");
        return head->data;
    }
    int back(){
        if(head == nullptr) throw length_error("List is empty.");
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        return current->data;
    }
    void print(){
        if(head == nullptr) return;
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr";
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    LinkedList ll;
    ll.push_front(10);
    ll.push_back(20);
    ll.insert(1, 15);
    ll.push_back(30);
    ll.push_back(40);
    ll.remove(3);
    if(ll.find(40)){
        cout << "40 is present in the list";
    }else{
        cout << "40 is not found in the list";
    }
    cout << '\n';
    ll.print();
    return 0;
}