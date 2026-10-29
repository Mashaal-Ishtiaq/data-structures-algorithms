#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    friend class BST;
};

class BST
{

public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    // Node *Search(Node *root, int val)
    // {
    //     if (root == NULL)
    //     {
    //         return NULL;
    //     }
    //     else if (root->val == val)
    //         return root;

    //     else if (root->val > val)

    //         return Search(root->left, val);

    //     else
    //         return Search(root->right, val);
    // }

    void Inorder(Node *root) // pre order instead
    {
        if (root)
        {

            Inorder(root->left);

            cout << root->val << " ";

            Inorder(root->right);
        }
    }
};

int main()
{
    BST s1;

    // hard code as insert function is done in 2nd question
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->right = new Node(3);
    root->left->left = new Node(1);

    cout << "\nInput: [" << root->val << "," << root->left->val << "," << root->right->val << "," << root->left->right->val << "]" << endl;

    s1.Inorder(r);
    // {
    //     s1.Inorder(result);
    // }
    // else
    // {
    //     cout << "[]";
    // }
    // cout << endl;

    // // 2nd example

    // int value2 = 9;

    // result = s1.Search(root, value2);

    // cout << "\nValue2: " << value2 << endl;
    // cout << "Output2 : ";
    // if (result)
    // {
    //     s1.Inorder(result);
    // }

    // else
    // {
    //     cout << "[]";
    // }
    // cout << endl;

    return 0;
}