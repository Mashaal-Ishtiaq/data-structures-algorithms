#include <iostream>
using namespace std;

class Node
{

private:
    int val;
    Node *left;
    Node *right;

public:
    Node()
    { // default constructor
        this->val = 0;
        left = right = NULL;
    }

    Node(int val)
    { // parameterized constructor
        this->val = val;
        left = right = NULL;
    }

    friend class BST;
};

class BST
{

private:
    Node *root;

public:
    BST()
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

        else
        {
            if (node->val == val)
            {
                cout << "Already Exist" << endl;
                return node;
            }
            else if (val < node->val)
                node->left = insert(node->left, val);
            else
            {
                node->right = insert(node->right, val);
            }
            return node;
        }
    }
    void insert_node(int val)
    {

        insert(root, val);

        cout << "Node has been successfully inserted" << endl;
    }

    int InOrderTraversal(Node *temp)
    { // here temp is root node

        if (temp == NULL)
            return 0;
        InOrderTraversal(temp->left);

        cout << temp->val << "\t";

        InOrderTraversal(temp->right);

        return 0;
    }

    int PreOrderTraversal(Node *temp)
    {

        if (temp == NULL)
            return 0;

        cout << temp->val << "\t";

        InOrderTraversal(temp->left);

        InOrderTraversal(temp->right);

        return 0;
    }

    int PostOrderTraversal(Node *temp)
    {

        if (temp == NULL) // idicated that tree is empty
            return 0;

        InOrderTraversal(temp->left);

        InOrderTraversal(temp->right);

        cout << temp->val << "\t";

        return 0;
    }

    int Smallest_value(Node *temp)
    {

        if (temp == NULL)
            return -1;

        Node *curr = temp->left;

        while (curr->left != NULL)
        {

            // as smaller values are on the left side of BST
            curr = curr->left;
        }
        cout << "Smallest value in the tree: " << curr->val << endl;

        return 0;
    }

    int Count_nodes(Node *temp)
    {

        if (temp == NULL)
            return 0;

        return Count_nodes(temp->left) + Count_nodes(temp->right) + 1; //+1 as there is root node as well
    }

    friend int main();
};

int main()
{
    BST bst;
    int choice, value, result;

    while (1)
    {

        cout << "\n_______Binary Search Tree Operations______\n";
        cout << "1. Insert a node\n";
        cout << "2. In-order Traversal\n";
        cout << "3. Pre-order Traversal\n";
        cout << "4. Post-order Traversal\n";
        cout << "5. Find Smallest Value\n";
        cout << "6. Count Nodes\n";
        cout << "7. Exit\n";

        cout << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:

            cout << "Enter the value" << endl;
            cin >> value;

            bst.insert_node(value);
            break;

        case 2:
            bst.InOrderTraversal(bst.root);
            break;

        case 3:
            bst.PreOrderTraversal(bst.root);
            break;

        case 4:
            bst.PostOrderTraversal(bst.root);
            break;

        case 5:
            bst.Smallest_value(bst.root);
            break;

        case 6:

            result = bst.Count_nodes(bst.root);

            cout << "Total nodes are: " << result << endl;
            break;

        case 7:
            cout << "Exiting..." << endl;
            return 0;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}