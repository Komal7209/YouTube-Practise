class Solution {
public:
        
    int solve(TreeNode* root, int pathSum){
       
        if(!root)return 0;
        
        pathSum = 10*pathSum + root->val;  // used for storing digits to number
        
        if(!root->left and !root->right) return pathSum;
        
        return solve(root->left, pathSum) + solve(root->right, pathSum);
    }  
    
    int sumNumbers(TreeNode* root) {
        int pathSum =0;        
        return solve(root, pathSum);
    }
};