#include <iostream>
#include <string>
#include <algorithm> // For reverse

using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char val)
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

    void push(char val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
        length++;
    }

    char pop()
    {
        if (isEmpty())
        {

            return 0;
        }
        else
        {
            Node *temp = top;
            char poppedVal = temp->data;
            top = top->next;
            delete temp;
            length--;
            return poppedVal;
        }
    }

    char Top()
    {

        return top->data;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    string Removeadjacent(string &str)
    {

        Stack st;

        for (char c : str)
        {

            if (!st.isEmpty() && st.Top() == c)
            {

                st.pop();
            }

            else
            {
                st.push(c);
            }
        }
        string result;

        while (!st.isEmpty())
        {

            result.push_back(st.pop()); // push_back used to append element at the end of string
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    string str = "abbaca";
    Stack s;
    string result = s.Removeadjacent(str);
    cout << "Result after removing adjacent duplicates: " << result << endl; // Output: "ca"
    return 0;
}