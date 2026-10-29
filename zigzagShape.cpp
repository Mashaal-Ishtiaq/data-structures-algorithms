int count = 0;

Node *zigzag(Node *node)

{
    if (node == NULL)
    {
        return new Node();

        count++;
    }
    else if (count % 2 == 0)
    {
        return zigzag(node->left);
    }
    else
    {
        return zigzag(node->right);
    }

    return node;
}