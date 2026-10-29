#include <iostream>
using namespace std;
class node
{
public:
    string data;
    node *next;

    node(string val)
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
    void insert(string val, int pos)
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
            cout << "bruhhh list is empty" << endl;
            return;
        }

        for (int i = 1; i <= length; i++)
        {
            cout << curr->data << "     \n";
            curr = curr->next;
        }
    }

    string getValue(int pos)
    {
        node *curr = head;
        for (int i = 1; i <= length; i++)
        {
            if (pos == i)
                return curr->data;
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
        // if(pos<1 || pos >=lenght+1)
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

int main()
{
    list l;
    l.insert("mashaal", 1);
    l.insert("aimen", 2);
    l.insert("aisha ", 3);
    l.insert("absar", 4);
    l.insert("hazika", 5);

    int input;
    int count = 1;
    while (1)
    {
        cout << "1. Traverse the Wizard one by one:" << endl;
        cout << "2. start game " << endl;
        cout << "3. exit" << endl;
        cin >> input;

        if (input == 1)
        {
            cout << l.getValue(count) << endl;
            while (1)
            {
                cout << "show:" << endl;
                cout << "1. next" << endl;
                cout << "2. go to main menu" << endl;
                int a;
                cin >> a;
                if (a == 1)
                {
                    count++;
                    cout << l.getValue(count) << endl;
                }
                else
                    break;
            }
        }
        else if (input == 2)
        {
            cout << "Current Wizard are :" << endl;
            l.display();
            while (l.get_length() != 1)
            {
                int max = l.get_length();
                int random = rand() % max + 1;
                cout << endl;
                cout << "Random NUmber is " << random << endl;
                cout << l.getValue(random) << " is removed from the game" << endl;
                l.remove(random);
                cout << "Current Wizard are: " << endl;
                l.display();
                cout << endl;
            }
            cout << "winner :" << l.getValue(1) << endl;
        }
        else if (input == 3)
            break;
        else
            cout << "invalid input" << endl;
    }
}