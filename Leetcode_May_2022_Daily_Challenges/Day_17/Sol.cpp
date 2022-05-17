class Solution {
    TreeNode* ans, *target;
    
     void inorder(TreeNode* original, TreeNode* cloned) {
        if (original != nullptr) {
            inorder(original->left, cloned->left);
            if (original == target) {
                ans = cloned;    
            }
            inorder(original->right, cloned->right);    
        }
    }
    
    public: 
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        this->target = target;
        inorder(original, cloned);
        return ans;
    }
};