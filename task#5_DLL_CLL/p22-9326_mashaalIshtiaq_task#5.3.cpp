#include<iostream>
#include<string>
using namespace std;

class Node
 {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string song)
     {
        data = song;
        next = nullptr;
        prev = nullptr;
    }
 };

class Playlist
{
    Node* head;
    int length;

public:
    Playlist() 
    {
        head = nullptr;
        length = 0;
    }

~Playlist() {
        if (head != nullptr) {
            Node* curr = head->next;
            while (curr != head) {
                Node* temp = curr;
                curr = curr->next;
                delete temp; //we will delete the middle nodes first so that list is not dangling
            }
            head->next = nullptr; 
            delete head; 
        }
    }
     

    
    void insert(string song)
{
    Node* n = new Node(song);
    if (head == nullptr) 
    {
        head = n;
        head->next = head;
        head->prev = head; 
    } 
    else 
    {
        Node* tail = head->prev;

        n->next = head;
        n->prev = tail;
        tail->next=n;
        head->prev=n;
        // head= n;

    }  
    length++;
}

        
     


    void remove()
     {
        if (head == nullptr)
         {
            cout << "Playlist is empty" << endl;
            return;
            
        }
        if (head->next == head && head->prev == head) 
        {
            delete head;
            head=nullptr;
            return;
        
        }
        else {
           
            Node* tail = head->prev;
            Node* temp = tail->prev;
            temp->next = head;
            head->prev = temp;
            delete tail;
            }
            
            
        
        
            length--; 
       
    }

     void display()
{  
    if (head == nullptr) {
        cout << "Playlist is empty" << endl;
        return;
    }
    
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);

    cout << endl;
}

    
};

int main()
 {
    Playlist playlist;
    int choice;

    while (true) 
    {
        cout <<"___SONG PLAYLIST___" "\n1. Add Song at Beginning\n"<< "2. Remove Song at End\n"<< "3. Display Playlist\n"<< "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        

        if (choice == 1)
         {
            string song;
            cout << "Enter the name of the song: ";
           
           cin>>song;
            playlist.insert(song);
            cout << "Song added to the beginning of the playlist.\n";
        } 
        else if (choice == 2)
         {
            playlist.remove();
            cout << "Last song removed from the playlist.\n";
        } 
        else if (choice == 3)
         {
            cout << "Playlist: ";
            playlist.display();
        } 
        else if (choice == 4)
         {
            cout << "Exiting...\n";
            return 0;
        }
         else 
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}