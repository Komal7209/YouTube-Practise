class Solution{
    private: int count = 0;
    
    public:
    
    int pathSum(TreeNode* root, int targetSum)
        {
            recurse(root, targetSum, false);
            return count;
        }

    // when true then can traverse at max n nodes 
    // when false calls true and false
    // each false calls true
    // each n node calls n nodes thus tc: n^2
    
    
    void recurse(TreeNode* root, int sum, bool must)
        {
            if (root == nullptr) return;
            if (root->val == sum) { count++; }
            if (!must)
            {  
                recurse(root->left, sum, false);
                recurse(root->right, sum, false);
            }
            
        // below will be called when each node backtrack when base case is hit
            
            recurse(root->left, sum - root->val, true);
            recurse(root->right, sum - root->val, true);
        
     }
};
