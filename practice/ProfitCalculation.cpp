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
    // friend int main();
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

    int FindmaxProfit(Node *head)
    {
        if (head == NULL)
        {
            return -1;
        }
        int minPrice = head->val;
        int maxProft = 0;

        while (head != NULL)
        {

            if (head->val < minPrice)
            {

                minPrice = head->val;
            }

            else if ((head->val - minPrice) > maxProft)
            {

                maxProft = head->val - minPrice;
            }
            head = head->next;
        }
        return maxProft == 0 ? -1 : maxProft;
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
    l.insert(7);
    l.insert(1);
    l.insert(5);
    l.insert(3);
    l.insert(6);
    l.insert(4);

    cout << "Original List: ";
    l.display();

    int max = l.FindmaxProfit(l.head);
    if (max == -1)
    {
        cout << "No profit can be made." << endl;
    }
    else
    {
        cout << "Maximum profit: " << max << endl;
    }

    return 0;
}
