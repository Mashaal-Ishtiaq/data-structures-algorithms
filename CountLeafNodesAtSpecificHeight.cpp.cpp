int currentH = 1;

int countLeafHeight(Node *node, targetHeight, currentH)
{
    if (root == NULL)
    {
        return 0;
    }

    if (currentH == targetHeight)
    {
        if (root->left == NULL && root->right == NULL)
            return 1;

        else
        {
            return 0;
        }
    }

    int leftCount = countHeightAt(root->left, targetHeight, currentH + 1);
    int rightCount = countHeightAt(root->right, targetHeight, currentH + 1);

    return leftCount + rightCount;
}