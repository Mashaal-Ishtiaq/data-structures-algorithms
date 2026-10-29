#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
private:
    int size;
    Node *front;
    Node *rear;

public:
    Queue()
    {
        size = 0;
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        // As the queue is implemented using a linked list, it can never be full.
        return false;
    }

    void Display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = front;
        cout << "Orders in Queue:" << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Enqueue(int d)
    {
        Node *newNode = new Node(d);
        if (!isFull())
        {
            if (isEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }
        else
        {
            cout << "Queue is full. Cannot add more orders." << endl;
        }
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No orders to process." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }
};

int main()
{
    Queue q;
    int choice;

    cout << "____KASHMIRI CAFE(FAST PWR CAMPUS)____" << endl;
    do
    {
        cout << "Menu Options:" << endl;
        cout << "1. Add New Order" << endl;
        cout << "2. Process Order" << endl;
        cout << "3. Display Current Orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << " Menu For Nashta " << endl;
            cout << "1. chai (Rs.80)" << endl;
            cout << "2. Paratha (Rs.100)" << endl;
            cout << "3. channay (Rs.120)" << endl;
            cout << "4. roll (Rs.30)" << endl;
            cout << "5. samosa (Rs.25)" << endl;
            int order;
            cout << "Select your order: ";
            cin >> order;
            q.Enqueue(order); // order number will be added to the queue
            break;
        }
        case 2:
        {
            if (!q.isEmpty())
            {
                cout << "Processing order.. " << endl;
                q.Dequeue(); // removing the order from the queue
                q.Display();
                cout << endl;
            }
            else
            {
                cout << "No orders in queue to process." << endl;
            }
            break;
        }
        case 3:
            q.Display();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
