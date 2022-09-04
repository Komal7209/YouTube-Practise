// dfs
class Solution {
private:
    vector<vector<int>> ans;    
    map<int,multiset<pair<int,int>>> mp;
    
public:
    // preoder traversal
    void solve(TreeNode* root,int row,int col){
        if(!root)return ;
        mp[col].insert({row,root->val}); // width, height, value
        solve(root->left,row+1,col-1); // col-1 bcoz of left subtree
        solve(root->right,row+1,col+1);// col+1 bcoz of right subtree
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        mp.clear();
        solve(root,0,0);
        for(auto x:mp){ //col, height and value
            vector<int> v;
            for(auto z:x.second){// height n value
                v.push_back(z.second); // pushing values according to ascending row for that width
            } 
            ans.push_back(v);
        }
        return ans;
    }
};
