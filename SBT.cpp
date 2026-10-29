Bool SBT(Node *root)
{

    if (root == NULL)
    {
        return true;
    }

    if (() root->left == NULL && root->right == NULL)
        || (root->left != NULL && root->right != NULL)
        {

            return SBT(root->left) && SBT(root->right);
        }
    else
    {
        return false;
    }
}