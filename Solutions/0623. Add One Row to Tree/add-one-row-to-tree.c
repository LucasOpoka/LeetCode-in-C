struct TreeNode *get_node(int val) {
    struct TreeNode *node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void rc(struct TreeNode *node, int val, int depth, int curr) {
    if (depth == 1) {
        struct TreeNode *new = get_node(node->val);
        new->left = node->left;
        new->right = node->right;
        node->val = val;
        node->left = new;
        node->right = NULL;
        return;
    }
    if (node->left && curr + 1!=depth) rc(node->left, val, depth, curr + 1);
    if (node->right && curr + 1!=depth) rc(node->right, val, depth, curr + 1);
    if (curr + 1 == depth) {
        struct TreeNode *new_left = get_node(val);
        new_left->left = node->left;
        node->left = new_left;
        struct TreeNode *new_right = get_node(val);
        new_right->right = node->right;
        node->right = new_right;
        return;
    }
}

struct TreeNode* addOneRow(struct TreeNode* root, int val, int depth) {
    rc(root, val, depth, 1);
    return root;    
}
