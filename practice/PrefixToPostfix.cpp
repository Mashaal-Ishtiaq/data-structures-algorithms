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

    string PrefixToPostFix(const string &prefix)
    {

        Stack s;
        for (int i = prefix.size() - 1; i >= 0; i--)
        {
            char c = prefix[i];

            if (isalnum(c))
            {
                s.push(string(1, c)); // Convert char to string and push
            }
            else if (isOperator(c))
            {

                string operand1 = s.pop();
                string operand2 = s.pop();

                string postfix = operand1 + operand2 + c;

                s.push(postfix);
            }
        }
        return s.pop();
    }
};

int main()
{
    Stack s;
    string prefix = "*-A/BC";
    string postfix = s.PrefixToPostFix(prefix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}