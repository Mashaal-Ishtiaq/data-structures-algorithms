#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkList {
public:
    Node* head;
    Node* tail;
    int length;

    DoublyLinkList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

   void insert(int element) {
    Node* n = new Node(element);

    if (head == nullptr) {
        head = n;
        tail = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;  
    }
    length++;
}

    void splitList(DoublyLinkList& evenList, DoublyLinkList& oddList) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data % 2 == 0) {
                evenList.insert(curr->data);
            } else {
                oddList.insert(curr->data);
            }
            curr = curr->next;
        }
    }

    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkList originalList;

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++) {
        int elements;
        cin >> elements;
        originalList.insert(elements);
    }

    DoublyLinkList evenList;
    DoublyLinkList oddList;

    originalList.splitList(evenList, oddList);

    cout << "Even List: ";
    evenList.display();

    cout << "Odd List: ";
    oddList.display();

    return 0;
}
