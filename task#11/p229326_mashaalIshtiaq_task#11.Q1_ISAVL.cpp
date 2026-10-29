#include <iostream>
using namespace std;

class Node
{

private:
    int val;
    Node *left;
    Node *right;
    int height;

public:
    Node(int val)
    { // parameterized constructor
        this->val = val;
        left = right = NULL;
        height = 1;
    }

    friend class AVL;
    friend int main();
};

class AVL
{
private:
    // public:
    Node *root;

public:
    AVL()
    {
        root = NULL;
    }

    Node *insert(Node *node, int val)
    {
        if (node == NULL)
        {
            Node *temp = new Node(val);
            if (root == NULL)
            {
                root = temp;
            }

            return temp;
        }

        if (val < node->val)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->val)
        {
            node->right = insert(node->right, val);
        }

        node->height = updateHeight(node);
        return node;
    }

    int getHeight(Node *node)
    {
        if (node == NULL)
            return 0;

        return node->height;
    }

    int updateHeight(Node *node)
    {
        if (node == NULL)
            return 0;

        int rightH = getHeight(node->right);
        int leftH = getHeight(node->left);

        return 1 + max(leftH, rightH); // return 1+[(left > right) ? left : right ]
    }

    bool findAVL(Node *node)
    {
        if (node == NULL)
            return true;

        int rightH = getHeight(node->right);
        int leftH = getHeight(node->left);

        if ((leftH - rightH) <= 1 && findAVL(node->left) && findAVL(node->right)) // <=1 ->it includes -1 as well
        {
            return true;
        }

        return false;
    }
    friend int main();
};

int main()
{
    AVL avl;
    // hard code

    avl.root = NULL;
    avl.insert(avl.root, 50);
    avl.insert(avl.root, 30);
    avl.insert(avl.root, 70);
    avl.insert(avl.root, 20);
    avl.insert(avl.root, 40);
    avl.insert(avl.root, 60);
    avl.insert(avl.root, 80);

    if (avl.findAVL(avl.root))
    {
        cout << "AVL" << endl;
    }
    else
    {
        cout << "Not AVL" << endl;
    }
}
