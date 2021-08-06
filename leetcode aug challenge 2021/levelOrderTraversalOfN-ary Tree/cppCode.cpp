// bfs

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        
        if (root == NULL) return {};
        
        q.push(root); 
      
        while (!q.empty())
        {
            int size = q.size(); 
            vector<int>currlevel;
            
            for(int i=0;i<size;i++){
                
                Node* currNode=q.front();
                q.pop();
                
                currlevel.push_back(currNode->val);
                for (auto n : currNode -> children)
                     q.push(n); 
            }
            res.push_back(currlevel);
        }
        return res;
    }
};
