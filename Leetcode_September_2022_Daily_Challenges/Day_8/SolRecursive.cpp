
// recursive approach

class Solution {
    private:  vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        
        return ans;
    }
};

