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

    Node *DetectCycle(Node *head)
    {

        if (head != NULL || head->next != NULL)
        {
            Node *slow = head;
            Node *fast = head;

            while (true)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                {
                    break;
                }
            }
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
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
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    l.display();

    Node *cycle = l.DetectCycle(l.head);
    if (cycle != NULL)
    {
        cout << "Cycle detected at node " << cycle->val << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }

    return 0;
}