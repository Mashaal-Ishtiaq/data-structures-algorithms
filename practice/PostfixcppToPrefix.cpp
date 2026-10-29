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

    bool isOperator(char c)
    {

        return (c == '+' || c == '-' || c == '/' || c == '*');
    }

    string PostFixToPrefix(const string &postfix)
    {

        Stack s;
        for (char c : postfix)
        {

            if (isalnum(c))
            {
                s.push(string(1, c)); // Convert char to string and push
            }
            else if (isOperator(c))
            {

                string operand2 = s.pop();
                string operand1 = s.pop();

                string prefix = c + operand1 + operand2;

                s.push(prefix);
            }
        }
        return s.pop();
    }
};

int main()
{
    Stack s;
    string postfix = "ABC/-*";
    string prefix = s.PostFixToPrefix(postfix);
    cout << "Prefix: " << prefix << endl;
    return 0;
}