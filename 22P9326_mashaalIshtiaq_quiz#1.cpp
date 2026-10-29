#include <iostream>
#include<cstring>
#include <string>

using namespace std;

class Node
{

public:
    char info;
    Node *prev;
    Node *next;
    Node(char input)
    {

        info = input;
        prev = next = NULL;
    }
};

class List
{
public:
    int length;
    Node *head;
    // Node *tail;
    List()
    {
        head = NULL;
       // tail = NULL;
        length = 0;
    }

    bool isVowel(){

        if('a' || 'e' ||'i' || 'o' || 'u')
        return true;

        else
         return false;
       
       
       
    }
    

   void Encryption(const char* str){
        
         int length = strlen(str);
        
                  
         for (int i = 0; i < length; ++i) {
        
        while(head != NULL){
        if(append(str[i])!= isVowel())
        {
            cout<< append(str[i])<<append('X')<<info->pos<<endl;
        }
        
        else if(append(str[i])== isVowel()){
            cout << append(str[i])<<append('Y')<<append('Y')<<info->pos<<endl;
        }
       else {
          cout<<append(str[i])*append(str[i])<<endl;
       }
        }
 }
       Node *start = head;
 Node *tail = NULL;
    }
    

    char append(char input)
    {
    Node *n= new Node(input);
        

        Node *temp = head;
        if (head == NULL)
        {
            head = n;
        }

        else
        {

            while (temp->next != NULL)
                temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;

       

       
    }
    ~List() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
};

int main()
{
    char input[100];
    cout << "Enter string: ";
    cin >> input;

    List list;

    list. Encryption(input);
}
