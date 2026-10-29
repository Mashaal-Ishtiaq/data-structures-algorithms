#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
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

    void push(int val)
    {
        Node *n = new Node(val);
        n->next = top;
        top = n;
        length++;
    }

    int pop()
    {
        if (isEmpty())
        {

            return 0;
        }
        else
        {
            Node *temp = top;
            int poppedVal = temp->data;
            top = top->next;
            delete temp;
            length--;
            return poppedVal;
        }
    }

    int Top()
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

    void SortStack1(Stack &stack1, Stack &stack2, Stack &stack3)
    {

        while (!stack1.isEmpty())
        {

            int temp = stack1.pop();

            while (!stack2.isEmpty() && stack2.Top() > temp)
            {

                stack3.push(stack2.pop());
            }

            stack2.push(temp);

            while (!stack3.isEmpty())
            {

                stack2.push(stack3.pop());
            }
        }
    }
};
int main()
{
    Stack stack1;
    Stack stack2;
    Stack stack3;

    stack1.push(3);
    stack1.push(1);
    stack1.push(4);
    stack1.push(2);

    Stack sorter;
    sorter.SortStack1(stack1, stack2, stack3);

    while (!stack2.isEmpty())
    {
        cout << stack2.pop() << " ";
    }

    return 0;
}