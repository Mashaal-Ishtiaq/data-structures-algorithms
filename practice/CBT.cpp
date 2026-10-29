#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    bool isCompleteBT(node *root, int level, int &max_nodes)
    {
        if (root == NULL)
            return true;

        if (level > max_nodes)
            return false;

        if (level == max_nodes)
            return (root->left == NULL && root->right != NULL);

        return isCompleteBT(root->left, level + 1, max_nodes) && isCompleteBT(root->right, level + 1, max_nodes);

        // friend int main();
    }
};

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    int max_nodes = 3;
    if (isCompleteBT(root, 1, max_nodes))
        cout << "Complete Binary Tree";
    else
        cout << "NOT Complete Binary Tree";

    return 0;
}