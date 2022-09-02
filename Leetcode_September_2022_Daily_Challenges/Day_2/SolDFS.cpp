

// dfs 
class Solution{
    
    private:
        void solve(TreeNode* root, unordered_map<int, pair<int, long> >&nodes, int lvl){
        if(!root)return;
       //   level     count,                sum of nodes of same level
        nodes[lvl] = {nodes[lvl].first + 1, nodes[lvl].second + root -> val};
        solve(root -> left, nodes, lvl + 1);
        solve(root -> right, nodes, lvl + 1);
    }
    
    public:
        vector<double> averageOfLevels(TreeNode* root) {       
                    //level     count,sum
        unordered_map<int, pair<int, long> >nodes; 
        solve(root, nodes, 0);
        vector<double> ans(nodes.size());
        for(int i=0;i<ans.size();i++)
            ans[i] = (double)nodes[i].second / nodes[i].first;
        return ans;
    }

};