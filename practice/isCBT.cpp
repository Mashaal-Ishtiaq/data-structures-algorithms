bool isCBT(Node *root, int index, int count)
{

    if (root == NULL)
        return true;

    if (index >= count)
        return false;

    return (isCBT(root->left, (2 * index) + 1, count) && isCBT(root->right, (2 * index) + 2, count));
}