class Solution {
    private:
     vector<int>adj[500001];
    bool vis[500001];
    bool can;
        void dfs(int u, int par, int destination)
        {
            if(u == destination)can=true;
            vis[u]=true;
            for(auto v : adj[u])
            {
               if(!vis[v]){
                dfs(v, u, destination );}
            }
        }
        
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        for( int i =0; i<edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(source,-1, destination);   
        return can;
        
    }
};