#include <iostream>
using namespace std;
class node
{
public:
    char data;
    node *next;

    node(char val)
    {
        data = val;
        next = NULL;
    }
};

class list
{
public:
    node *head;
    int length;
    list()
    {
        head = NULL;
        length = 0;
    }
    ~list()
    {
    }
    void insert(char val, int pos)
    {

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        node *n = new node(val);
        node *curr = head;
        if (head == NULL)
        {
            head = n;
            head->next = head;
        }
        else if (pos == 1)
        {
            n->next = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = n;
            head = n;
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }

        length++;
    }

    bool isempty()
    {
        if (length == 0)
            return true;
        else
            return false;
    }

    void display()
    {
        node *curr = head;
        if (isempty())
        {
            cout << "List is empty" << endl;
            return;
        }

        for (int i = 1; i <= length; i++)
        {
            cout << curr->data << "     \t";
            curr = curr->next;
        }
    }

    char get_val(int pos)
    {
        node *curr = head;
        for (int i = 1; i <= pos; i++)
        {
            if (pos == i)
            {
                return curr->data;
            }
            else
                curr = curr->next;
        }
    }

    void remove(int pos)
    {
        if (isempty())
        {
            cout << "list is empty" << endl;
            return;
        }

        if (pos < 1 || pos > length + 1)
            return;
        node *temp = head;
        node *tail = head;

        if (pos == 1)
        {
            while (tail->next != head)
            {

                tail = tail->next;
            }
            head = head->next;
            tail->next = head;

            if (head == head->next)
            {
                head = NULL;
            }
            delete temp;
        }
        else
        {
            node *slow = NULL;
            for (int i = 1; i < pos; i++)
            {
                slow = temp;
                temp = temp->next;
            }
            slow->next = temp->next;
            delete temp;
        }
        length--;
    }

    int get_length()
    {
        return length;
    }
};

class stack : public list
{
    int top;
    int rare;

public:
    stack()
    {
        top = 0;
    }
    void push(char val)
    {
        top++;
        insert(val, top);
    }
    char pop()
    {
        int val = get_val(top);
        remove(top);
        top--;
        return val;
    }
};

int main()
{
    stack s;
    cout << ".................WElCOME TO THE CAVE..................." << endl;
    while (1)
    {
        cout << "You must store your position so, u can run back when see a mummyxpappy" << endl;

        cout << "Enter a choice" << endl;
        cout << "1.Go forward in the cave " << endl;
        cout << "2.GO back in the cave" << endl;
        cout << "3.Run from the cave................ I saw mummy " << endl;
        int input;
        cin >> input;

        if (input == 1)
        {
            char a;
            cout << "Mark your current location so you can go back" << endl;
            cout << "Enetr the name of current position " << endl; // in single charcter only
            cin >> a;
            s.push(a);
        }
        else if (input == 2)
        {

            cout << "You are now at:" << s.pop() << endl;
        }
        else if (input == 3)
        {
            if (s.isempty())
            {
                cout << "You are not enterned in cave" << endl;
                break;
            }
            int l = s.get_length();
            while (l--)
            {
                cout << "You are know at:" << s.pop() << endl;
            }

            cout << "Congratulation you escaped from the cave successfully" << endl;
            break;
        }
        else
            break;
    }
}