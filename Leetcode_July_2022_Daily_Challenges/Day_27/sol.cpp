class Solution {
    private:
    TreeNode* flattenTree(TreeNode* node) {
        
        // Handle the null scenario
        if (node == nullptr) {
            return nullptr;
        }
            
        // For a leaf node, we simply return the
        // node as is.
        if (node->left == NULL && node->right == NULL) {
            return node;
        }
        
        //Recursively flatten the left subtree
        TreeNode* leftTail = flattenTree(node->left);
        
        // Recursively flatten the right subtree
        TreeNode* rightTail = flattenTree(node->right);
        
        // If there was a left subtree, we shuffle the connections
        // around so that there is nothing on the left side
        // anymore.
        if (leftTail != NULL) {
            leftTail->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        
        // We need to return the "rightmost" node after we are
        // done wiring the new connections. 
        return rightTail == nullptr ? leftTail : rightTail;
    }
    
    public:
    void flatten(TreeNode* root) {
        
        flattenTree(root);
    }
};