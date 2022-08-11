// TC: O(N)
// SC:O(N)

class Solution {
    private:
        bool  toCheck(TreeNode* minNode, TreeNode* root, TreeNode* maxNode){
            if(!root) return true;
            
            if(minNode && minNode->val >= root->val || maxNode && maxNode->val <= root->val) return false;
            
            return toCheck(minNode, root->left, root)  && toCheck(root, root->right, maxNode);
            
        }

    
public:
    bool isValidBST(TreeNode* root) {
     
        return toCheck(NULL, root, NULL);
    }
    
};