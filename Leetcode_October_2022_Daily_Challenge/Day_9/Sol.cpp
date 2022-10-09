class Solution {
    private: unordered_set<int> s;
public:     
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

