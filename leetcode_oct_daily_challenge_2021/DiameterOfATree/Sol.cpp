//TC: O(n)
//SC:O(1)
class Solution{
    private: int diameter = 0;
    public: 
         int height(TreeNode* root, int &diameter){
            if(!root) return 0;
            int leftHeight = height(root->left, diameter);
            int rightHeight = height(root->right , diameter);
            diameter = max(diameter, leftHeight+rightHeight); // for maintaining max diameter
            return 1+max(leftHeight,rightHeight);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            height(root, diameter);
            return diameter;
        }
};