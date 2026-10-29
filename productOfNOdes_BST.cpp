#include <iostream>
#include <stack>
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
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    bool inorderTraversal(stack<Node *> &inorderStack, Node *&current)
    {
        while (current)
        {
            inorderStack.push(current);
            current = current->left;
        }
        if (inorderStack.empty())
            return false;
        current = inorderStack.top();
        inorderStack.pop();
        return true;
    }

    bool reverseInorderTraversal(stack<Node *> &reverseInorderStack, Node *&current)
    {
        while (current)
        {
            reverseInorderStack.push(current);
            current = current->right;
        }
        if (reverseInorderStack.empty())
            return false;
        current = reverseInorderStack.top();
        reverseInorderStack.pop();
        return true;
    }

    bool findPairsWithProductK(Node *root, int k)
    {
        if (!root)
            return false;

        stack<Node *> inorder, reverseInorder;
        Node *current1 = root, *current2 = root;

        while (true)
        {
            // Move to the next smallest node in the BST
            bool move1 = inorderTraversal(inorder, current1);
            // Move to the next largest node in the BST
            bool move2 = reverseInorderTraversal(reverseInorder, current2);

            // If either traversal runs out of nodes, no pair exists
            if (!move1 || !move2)
                return false;

            Node *node1 = inorder.top();
            Node *node2 = reverseInorder.top();

            // If both pointers are pointing to the same node, break
            if (node1 == node2)
                break;

            int product = node1->val * node2->val;

            if (product == k)
            {
                return true;
            }
            else if (product < k)
            {
                // Move to the next smallest node
                inorder.pop();
                current1 = node1->right;
            }
            else
            {
                // Move to the next largest node
                reverseInorder.pop();
                current2 = node2->left;
            }
        }

        return false;
    }
};

int main()
{
    BST s1;

    // Hard code as insert function is done in the second question
    Node *root = new Node(100);
    root->left = new Node(50);
    root->right = new Node(200);
    root->left->left = new Node(25);
    root->left->right = new Node(75);
    root->right->left = new Node(125);
    root->right->right = new Node(300);

    int k = 250;
    bool result = s1.findPairsWithProductK(root, k);
    cout << "Do two elements in the BST multiply to " << k << "? " << (result ? "Yes" : "No") << endl;

    return 0;
}
