/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int level =-1;
        vector<int>values;
                
        while(!q.empty())  
        {   
            vector<int>temp;
            int len = q.size();
            level++;
            
            for( int i =0; i<len; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) 
                {
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
                
                if(level&1)
                {
                 curr->val = values[len-1 -i];  
                }   
            }
            values = temp;
        }
        
        return root;
    }
};