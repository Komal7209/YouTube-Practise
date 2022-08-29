// TC: O(k*k)
// SC: O(k)

class Solution {
private:
        // Same Code as Course Schedule - 2 
    vector<int> findOrder(int k, vector<vector<int>>& dependencies) {
                
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1);
        
        // creating graph + counting indegree
        for(auto dependency: dependencies) {
            adj[dependency[0]].push_back(dependency[1]);
            indegree[dependency[1]]++;
        }
        
        queue<int> q;
        // pushing all nodes with indegree 0 first (why till k=> as there are total k unique integers)
        for(int i = 1; i <= k; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int cnt = 0;
        vector<int> order;
        
        while(!q.empty()) {
            
            int cur = q.front();
            q.pop();
            
            cnt++;
            order.push_back(cur);
            
            // checking all neighbor nodes in adj list of cur
            for(int neighbor: adj[cur]) {
                indegree[neighbor]--;
                // after decreasing indegree if it becomes 0 that simply represent that there is no cycle for that node and thus we push it
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        if(cnt == k) return order;
        return {};
    }
    
public:

    // using topological sort for detecting cycle if any otherwise ans
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        // for finding indegree, detecting cycle and returning ans as per equality of number of nodes with conditions
        vector<int> rowArray = findOrder(k, rowConditions);
        vector<int> colArray = findOrder(k, colConditions);
        
        // If one of the row conditions or col conditions has a cycle
        if(rowArray.size() == 0 || colArray.size() == 0) {
            return {};
        }
        
        vector<pair<int, int>> ind(k); // first => row , second => col
        for(int i = 0; i < k; i++) {
            ind[rowArray[i] - 1].first = i;
            ind[colArray[i] - 1].second = i;
        }
        
        vector<vector<int>> result(k, vector<int>(k, 0));
        for(int i = 0; i < k; i++) {
            result[ind[i].first][ind[i].second] = i + 1;
        }
        return result;
    }
};
