void rc(struct TreeNode *node, int *res, char prev)
{
    if (node->left) rc(node->left, res, 'l');
    if (node->right) rc(node->right, res, 'r');
    if (prev == 'l' && !node->left && !node->right) *res += node->val;
}

int sumOfLeftLeaves(struct TreeNode *root)
{
    int res = 0;
    rc(root, &res, 'r');
    return res;
}
