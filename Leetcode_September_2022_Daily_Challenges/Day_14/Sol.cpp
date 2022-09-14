class Solution {
    private: 
        int count =0;
    
     void preorder(TreeNode* node, int path) {
        if (node) {
            // compute occurences of each digit 
            // in the corresponding register
            path = path ^ (1 << node->val);
            // if it's a leaf check if the path is pseudo-palindromic
            if (!node->left && !node->right) {
                // check if at most one digit has an odd frequency
                if ((path & (path - 1)) == 0) {
                    ++count;
                }
            }
            preorder(node->left, path);
            preorder(node->right, path);
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return count; 
    }
};

