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

    Node *kthSmallest(Node *root, int k)
    {
        if (root == NULL || k == 0)
            return nullptr;

        // Use a counter to keep track of the number of nodes visited
        int count = 0;
        Node *result = nullptr;

        // Perform an inorder traversal -> for ascending order
        Inorder(root, k, count, result);

        return result;
    }

    void Inorder(Node *node, int k, int &count, Node *&result)
    {
        if (node == NULL)
            return;

        Inorder(node->left, k, count, result);

        // Visit the current node
        count++;

        // Check if the current node is the kth smallest
        if (count == k)
        {
            result = node;
            return;
        }

        Inorder(node->right, k, count, result);
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

    int k = 2;

    Node *result = s1.kthSmallest(root, k);
    if (result != NULL)
    {
        cout << "The " << k << "th smallest node is: " << result->val << endl;
    }
    else
    {
        cout << "There is no " << k << "th smallest node." << endl;
    }

    return 0;
}