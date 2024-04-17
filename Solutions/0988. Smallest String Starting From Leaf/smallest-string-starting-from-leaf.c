char *rev(char* str)
{
    char* start = str;
    char* end = str + strlen(str) - 1;
 
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    return str;
}

void rc(struct TreeNode* node, int depth, char *curr, char **min)
{
    curr[depth] = node->val + 'a';
    curr[depth + 1] = 0;
    if (!node->left && !node->right)
    {
        char *temp = rev(strdup(curr));
        if (!*min) *min = temp;
        else if (strcmp(*min, temp) <= 0) free(temp);
        else
        {
            free(*min);
            *min = temp;
        }
    }
    if (node->left) rc(node->left, depth+1, curr, min);
    if (node->right) rc(node->right, depth+1, curr, min);
}

char* smallestFromLeaf(struct TreeNode* root)
{
    char *curr = (char*) calloc(21, sizeof(char));
    char **min = (char**) calloc(1, sizeof(char*));

    rc(root, 0, curr, min);
    free(curr);
    return *min;
}
