
// using bfs
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
     
        vector<double>ans;
        queue<TreeNode*>q;
        double sum =0;
        if(!root) return ans;
        q.push(root);
        
        while(!q.empty())
        {
            int levelCount = q.size();
            
            for( int i =0; i<levelCount; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            
            double average = 0.0;
            average = sum/levelCount;
            ans.emplace_back(average);
            sum =0;
        }
        
        return ans;
    }
};
