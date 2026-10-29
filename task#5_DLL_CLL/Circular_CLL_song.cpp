#include<iostream>
using namespace std;

class Node
 {
public:
    string data;
    Node* next;
    Node* prev;

    Node(string val)
     {
        data = val;
        next = nullptr;
    }
 };

class Song 
{
    Node* head;
    int length;

public:
    Song() 
    {
        head = nullptr;
        length = 0;
    }

   ~Song() {
    if (head != nullptr) {
        Node* curr = head->next;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp; // Deleting the current node
        }
        head->prev->next = nullptr; // Break the circular link
        delete head; // Delete the head node
    }
}


    
    void insert(string val, int pos)
     {
        Node* n = new Node(val);
        if (head == nullptr) 
        {
            head = n;
            head->next = head;
            head->prev = head; 
        } 
        else 
        {
            Node* tail = head->prev;
                tail->next = n;
                n->prev=tail;
                n->next = head;
                head->prev = n;
                head = n;
        }  
           length++;
        }
        
     


    void remove()
     {
        if (head == nullptr)
         {
            cout << "List is empty" << endl;
            return;
            
        }
        if (head->next == head && head->prev == head) 
        {
            delete head;
            return;
            length--;
        }
        else {
            Node* tail = head->prev;
            Node* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
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
    Song playlist;
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
            playlist.insert(song,1);
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