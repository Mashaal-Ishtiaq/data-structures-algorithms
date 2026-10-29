#include <iostream>
#include <cstring>
using namespace std;


class Node{
    public:
    char info;
    Node *prev;
    Node *next;

    Node(char input){
       
        info=input;
        prev=next=NULL;

    
    }
};

class List{
    public:
   
      int length;
      Node *head;


      List(){
        head=NULL;
        length=0;
      }
void append(char input) {
    Node* newNode = new Node(input);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

bool isPalindrome(const char* str) {
    int length = strlen(str);
     for (int i = 0; i < length; ++i) {
        append(str[i]);
    }

    Node *start = head;
    Node *tail = NULL;

    // Find the tail node
    while (start->next != NULL) {
        start = start->next;
    }
    tail = start;

    start = head; // Reset start to the beginning of the list

    // Compare nodes from start and tail
    while (start < tail) {
        if (start->info != tail->info) {
            return false;
        }
        start = start->next;
        tail = tail->prev;
    }
    return true;
}
   
  
};
int main() {
    char input[100];
    cout << "Enter string: ";
    cin >> input;

   List l;

    if (l.isPalindrome(input)) {
        cout << "The string is a palindrome.\n";
    } else {
        cout << "The string is not a palindrome.\n";
    }

    return 0;
}
 