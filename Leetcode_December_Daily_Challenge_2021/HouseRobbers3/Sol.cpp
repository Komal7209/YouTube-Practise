class Solution {
public:
  int rob(TreeNode* root) {
    int withoutRoot = 0;
    return helper(root, withoutRoot);
}

int helper(TreeNode* root, int& robNotMax)
{
    
    if (!root) return 0;
    
    int leftNotRobMax = 0, rightNotRobMax = 0;
    
    int leftMax     = helper(root->left,  leftNotRobMax);
    int rightMax    = helper(root->right, rightNotRobMax);
    
    int robMax = root->val + leftNotRobMax + rightNotRobMax;
    robNotMax = leftMax + rightMax;
    
    return max (robMax, robNotMax);
}
};
