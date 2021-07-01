// 3rd variation will be either of n1 or n2 is present

class Solution
{
public:
    bool findPath(TreeNode *root, vector<TreeNode *> nodes, int presentNode)
    {

        if (!root)
        {
            return false;
        }

        nodes.push_back(root);

        if (root->val == presentNode)
        {
            return true;
        }

        if (findPath(root->left, nodes, presentNode) || findPath(root->right, nodes, presentNode))
        {
            return true;
        }

        nodes.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2)
    {

        vector<TreeNode *> path1, path2;

        if (findPath(root, path1, node1) == false || findPath(root, path2, node2) == false)
        {
            return NULL;
        }

        for (int i = 0; i < path1.size() - 1 && i < path2.size(); i++)
        {
            if (path1[i + 1] != path2[i + 1])
                return path1[i];
        }

        return NULL;
    }
};
