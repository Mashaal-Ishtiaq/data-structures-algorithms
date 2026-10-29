int countNodesExpLeaf(Node *node)
{

    if (node == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
        return 0;

    int leftCount = countNodes(node->left);
    int rightCount = countNodes(node->right);

    return leftCount + rightCount + 1;
}