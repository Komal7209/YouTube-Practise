/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {

        return deep(root).second;
    }

    pair<int, TreeNode *> deep(TreeNode *root)
    {

        if (!root)
            return {0, NULL};

        pair<int, TreeNode *> left_node = deep(root->left), right_node = deep(root->right);

        int depth1 = left_node.first;
        int depth2 = right_node.first;

        return {max(depth1, depth2) + 1, depth1 == depth2 ? root : depth1 > depth2 ? left_node.second
                                                                                   : right_node.second};
    }
};