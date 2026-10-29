#include <iostream>
using namespace std;

class Node
{

private:
    int id;
    int salary;
    Node *left;
    Node *right;

public:
    Node()
    {
        salary = 0;
        id = 0;
        left = NULL;
        right = NULL;
    }

    Node(int id, int salary)
    {

        this->id = id;
        this->salary = salary;
        left = NULL;
        right = NULL;
        }
    friend class Employee;
    friend int main();
};

class Employee
{

private:
    Node *root;

public:
    Employee()
    {
        root = NULL;
    }

    //_______Insert_____

    // Node *insert(Node *node, int id, int salary)
    // {

    //     if (node == NULL)
    //     {
    //         cout << "Node not present" << endl;
    //         return NULL;
    //     }

    //        if (node->id == id)
    //         {
    //             cout << "Already Exist" << endl;
    //             return node;
    //         }
    //         // else if (id < node->id)
    //         //     node->left = insert(node->left, id, salary);
    //         // else
    //         // {
    //         //     node->right = insert(node->right, id, salary);
    //         // }
    //         return node;

    // }

    //______Search ______

    void search(Node *node, int startId, int endId)
    {
        if (node == NULL)
        {
            return;
        }
        ///____inorder
        search(node->left, startId, endId);

        if (node->id >= startId && node->id <= endId)

            cout << root->id << "\t";

        search(node->right, startId, endId);
    }

    //_____Finding total salary
    int TotalSalary(Node *node, int startId, int endId, int count)
    {

        if (node == NULL)
        {
            return 0;
        }

        //____left subtree

        int leftsal = TotalSalary(node->left, startId, endId, count);

        if (node->id >= startId && node->id <= endId)
        {

            count++;

            leftsal += node->salary;
        }

        //_____right subtree

        int righttsal = TotalSalary(node->right, startId, endId, count);

        return leftsal + righttsal;
    }
};

int main()
{
    Employee emp;
    int count = 0;
    // hard code
    Node *root;
    // root->left = NULL;
    // root->right = NULL;
    root = new Node(8, 1000);
    root->left = new Node(3, 2000);
    root->right = new Node(10, 3000);
    root->left->left = new Node(1, 4000);
    root->left->right = new Node(6, 4000);
    root->right->right = new Node(14, 5000);
    root->right->right->left = new Node(13, 8000);
    root->left->right->right = new Node(7, 6000);
    root->left->right->left = new Node(4, 7000);

    int startId = 6;
    int endId = 8;

    int totalsal = emp.TotalSalary(root, startId, endId, count);

    cout << "__Employees___" << endl;

    emp.search(root, startId, endId);

    cout << "Total salary:  " << totalsal << endl;

    return 0;
}
