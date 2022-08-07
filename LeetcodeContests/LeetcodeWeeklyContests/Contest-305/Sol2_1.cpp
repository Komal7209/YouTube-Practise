// Mark all restricted nodes as visited and run dfs from 0

// using dfs
// TC: O(n+e)
// SC: O(n)

class Solution {
public:
	int dfs(int node,vector<int>&vis,vector<int>adj[]){
		if(vis[node]) return 0; // as it was visited
		vis[node] = 1; // marking present node as visited , so that we dont visit it again
        
		int res = 0;
		for(int edge:adj[node]) 
            if(!vis[edge]) 
                res+=dfs(edge,vis,adj); // add up the result of the present node's dfs
			return res+1; // increment the result as we encountered valid node in this dfs
	}

	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
		vector<int>vis(n,0);
		for(auto x:restricted)
           vis[x] = 1;

		vector<int>adj[n];
		for(auto node:edges) 
            adj[node[0]].push_back(node[1]),adj[node[1]].push_back(node[0]);
            
		return dfs(0,vis,adj);
	}
};





