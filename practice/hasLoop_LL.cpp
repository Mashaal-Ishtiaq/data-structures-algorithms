
#include <iostream>
using namespace std;

class Node
{
private:
    int val;
    Node *next;

public:
    Node(int val)
    { // parameterized constructor
        this->val = val;
        next = NULL;
    }
    friend class List;
    friend int main();
};

class List
{
private:
    Node *head;

public:
    List()
    {
        head = NULL;
    }

    void insert(int val)
    {
        Node *n = new Node(val);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }

    bool hasLoop()
    {
        Node *ptr1 = head;
        Node *ptr2 = head;

        while (ptr1 != NULL && ptr2 != NULL && ptr2->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;

            if (ptr1 == ptr2)
            {
                return true;
            }
        }
        return false;
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    friend int main();
};

int main()
{
    List list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    list.display();

    // Create a loop
    Node *temp = list.head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list.head->next->next;

    if (list.hasLoop())
    {
        cout << "Loop detected" << endl;
    }
    else
    {
        cout << "No loop detected" << endl;
    }

    return 0;
}