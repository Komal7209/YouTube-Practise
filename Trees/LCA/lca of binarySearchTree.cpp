/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (!root)
            return NULL; // base condition

        if ((root == p) || (root == q)) // recursive check condition when we find either of them
            return root;

        TreeNode *lca1 = (lowestCommonAncestor(root->left, p, q)); // when in either or same for checking that
        TreeNode *lca2 = (lowestCommonAncestor(root->right, p, q));

        if ((lca1) && (lca2))
            return root; // when present in either of subtree

        if (lca1)
            return lca1; // when prsent in both
        else
            return lca2;
    }
};