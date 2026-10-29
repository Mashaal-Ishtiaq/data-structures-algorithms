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

    Node *OddEvenList(Node *head)
    {

        if (head != NULL || head->next != NULL)
        {
            return head;
        }

        Node *odd = head;
        Node *even = head->next;
        Node *evenHead = even;

        while (even != NULL && even->next != NULL)
        {

            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
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

    cout << "Original List: ";
    l.display();

    l.OddEvenList(l.head);

    cout << "List after rearranging: ";
    l.display();

    return 0;
}
