class Solution {
public:
    
        vector<vector<int>>ans;
        vector<int>temp;
    
    void solve(vector<int>temp, TreeNode* root, int targetSum){
        if(!root)return;
        temp.push_back(root->val);
             
        
        if(root->val == targetSum && !root->left && !root->right) {
            ans.push_back(temp); 
            return;      
        }    
        solve(temp,root->left, targetSum-root->val);
        solve(temp, root->right, targetSum-root->val);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        solve(temp, root, targetSum);
        return ans;
    }
};