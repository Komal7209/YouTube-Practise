class Solution {
public:
    int goodNodes(TreeNode* root, int maxFromRoot=INT_MIN) {
        
        // base case of recursion 
        if( root == NULL) return NULL; 
        
        int count = 0;
        
        // if the root value is >= max value till now 
        // we got a one good node, so increase the count 
        // also update the max value which we are going to pass for left and right subtree
        if( root->val >= maxFromRoot){ 
            count++;
            maxFromRoot = root->val;
        }
        
        // recursive call for sub problem 
        count += goodNodes( root->left , maxFromRoot );
        count += goodNodes( root->right , maxFromRoot );
        
        // returning the final ans
        return count;
    }
};