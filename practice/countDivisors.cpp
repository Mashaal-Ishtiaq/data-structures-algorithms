int countDivisors(Node *node, int val)
{

    int count = 0;

    if (node == NULL)
    {
        return 0;
    }

    if (val % node->data == 0)
    {

        count++;
    }

    count += countDivisors(node->left, val);
    count += countDivisors(node->right, val);

    return count;
}