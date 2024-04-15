void rc(struct TreeNode *node, int curr, int *res)
{
    if (node->left) rc(node->left, curr * 10 + node->val, res);
    if (node->right) rc(node->right, curr * 10 + node->val, res);
    if (!node->left && !node->right) *res += curr * 10 + node->val; 
}

int sumNumbers(struct TreeNode* root)
{
    int res = 0;
    rc(root, 0, &res);
    return res;   
}