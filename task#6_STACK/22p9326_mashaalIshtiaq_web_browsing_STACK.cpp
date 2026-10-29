#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node *next;

    Node(string val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    int limit;
    int length;

    Stack(int limit) : top(nullptr), limit(limit), length(0)
    {
    }
    // constructor overloading + default constructor
    Stack() : top(nullptr), limit(0), length(0)
    {
    }

    bool isEmpty()
    {
        return top == nullptr && length == 0;
    }

    bool isFull()
    {
        return length == limit;
    }

    void push(string val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
        length++;
    }

    string pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return "";
        }
        else
        {
            Node *temp = top;
            string poppedVal = temp->data;
            top = top->next;
            delete temp;
            length--;
            return poppedVal;
        }
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

class Browser
{

public: // all the data members are set public to avoid getter and setters
//objects
    Stack forwardNavigationStack;
    Stack backNavigationStack;
    string currentURL;

    Browser() : currentURL("") {}

    ~Browser()
    {
    }

    void visit(const string &URL)
    {
        if (!currentURL.empty())
        {
            backNavigationStack.push(currentURL);
        }

        currentURL = URL;

        if (forwardNavigationStack.isEmpty())
        {
            forwardNavigationStack.push(currentURL);
        }

        cout << "Visited " << currentURL << endl;
    }

    void back()
    {
        if (backNavigationStack.isEmpty())
        {
            cout << "Can't go back as there are no pages at back" << endl;
            return;
        }
        else
        {
            currentURL = backNavigationStack.pop();
            forwardNavigationStack.push(currentURL);
            cout << "Back to: " << currentURL << endl;
        }
    }

    void forward()
    {
        if (forwardNavigationStack.isEmpty())
        {
            cout << "Can't go forward as there are no pages at forward" << endl;
            return;
        }
        else
        {
            currentURL = forwardNavigationStack.pop();
            backNavigationStack.push(currentURL);
            cout << "Forward to: " << currentURL << endl;
        }
    }

    void display()
    {
        cout << "Current URL: " << currentURL << endl;
    }
};

int main()
{
    int choice;
    string URL;
    Browser B;

    cout << "___WEB BROWSING___" << endl;
    while (true)
    {
        cout << "1. Visit a page" << endl
             << "2. Navigate back" << endl
             << "3. Navigate forward" << endl
             << "4. Display current page" << endl
             << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter URL: ";
            cin >> URL;
            B.visit(URL);
            break;
        case 2:
            B.back();
            break;
        case 3:
            B.forward();
            break;
        case 4:
            B.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}
