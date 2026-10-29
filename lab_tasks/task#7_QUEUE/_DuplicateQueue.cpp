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
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    ~Queue()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            front = front->next;
            delete temp;
            temp = front;
        }
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void Enqueue(int d)
    {
        Node *newNode = new Node(d);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

   

    void Display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = front;
        while (temp != NULL)
        {

            if (temp != front)
            {
                cout << "->";
            }
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to duplicate nodes in the queue based on their data
    void DuplicateQueue()
    {
        Node *curr = front;
        while (curr != NULL)
        {
            int data = curr->data;
            for (int i = 1; i < data; i++)
            {
                Node *newNode = new Node(data);
                newNode->next = curr->next;
                curr->next = newNode;
                curr = curr->next;

                // if (curr == rear)
                // {
                //     rear = newNode;
                // }
            }
            curr = curr->next;
        }
    }
};

int main()
{
    Queue q;
    char ch = 'Y';

    cout << "Enter numbers into the queue (-1 to stop):" << endl;
    int num;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        q.Enqueue(num);
    }
    // q.Enqueue(2);
    // q.Enqueue(3);
    // q.Enqueue(2);

    cout << "Original Queue: ";
    q.Display();

    // Duplicate the queue
    q.DuplicateQueue();

    cout << "Duplicated Queue: ";
    q.Display();

    return 0;
}
