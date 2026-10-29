#include <iostream>
using namespace std;

// Define the Stack class
template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *top;

public:
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(T data)
    {
        Node *newNode = new Node{data, top};
        top = newNode;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow." << endl;
            exit(1);
        }
        T data = top->data;
        Node *temp = top;
        Node *
            top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }
};

// Function to sort stack1 using stack2 and stack3
void sortStack1(Stack<int> &stack1, Stack<int> &stack2, Stack<int> &stack3)
{
    while (!stack1.isEmpty())
    {
        int temp = stack1.pop();
        while (!stack2.isEmpty() && stack2.top()->data > temp)
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

int main()
{
    Stack<int> stack1, stack2, stack3;

    // Push five random numbers into stack1
    stack1.push(34);
    stack1.push(12);
    stack1.push(56);
    stack1.push(78);
    stack1.push(90);

    cout << "Before sorting:" << endl;
    while (!stack1.isEmpty())
    {
        cout << stack1.pop() << " ";
    }
    cout << endl;

    sortStack1(stack1, stack2, stack3);

    cout << "After sorting:" << endl;
    while (!stack1.isEmpty())
    {
        cout << stack1.pop() << " ";
    }
    cout << endl;

    return 0;
}
