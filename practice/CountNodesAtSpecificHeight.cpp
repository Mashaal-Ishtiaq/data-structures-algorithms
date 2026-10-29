int currentH = 1;

int countHeightAt(Node *node, targetHeight, currentH)
{
    if (root == NULL)
    {
        return 0;
    }

    if (currentH == targetHeight)
    {

        return 1;
    }

    int leftCount = countHeightAt(root->left, targetHeight, currentH + 1);
    int rightCount = countHeightAt(root->right, targetHeight, currentH + 1);

    return leftCount + rightCount;
}