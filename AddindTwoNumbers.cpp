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

    Node *addTwoNumbers(Node *l1, Node *l2)
    {
        Node *dummy = new Node(0);
        Node *p = dummy;
        int carry = 0;

        while (carry > 0 || l1 != NULL || l2 != NULL)
        {
            int sum = carry;
            if (l1 != NULL)
            {

                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {

                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            p->next = new Node(sum % 10);
            p = p->next;
        }

        return dummy->next;
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
