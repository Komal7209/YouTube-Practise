class Solution
{
public:
    int res = 0;
    int findTilt(TreeNode *root)
    {
        DFS(root);
        return res;
    }

    int DFS(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int leftNode = DFS(node->left);
        int rightNode = DFS(node->right);
        res += abs(leftNode - rightNode);
        return leftNode + rightNode + node->val;
    }
};