// tc :O(n)
// sc : O(n)

class Solution {
public:
   long res = 0, total = 0, sub;
    int maxProduct(TreeNode* root) {
        total = subAndSum(root), subAndSum(root);
        return res % (int)(1e9 + 7);
    }

    int subAndSum(TreeNode* root) {
        if (!root) return 0;
        sub = root->val + subAndSum(root->left) + subAndSum(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }
};