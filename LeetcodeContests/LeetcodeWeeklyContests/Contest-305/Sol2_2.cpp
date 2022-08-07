// using bfs 

class Solution{
public:
    int reachableNodes(int n, vector<vector<int>>&e , vector<int>& r) {
        
        vector<vector<int>> graph(n); // for graph
        
        // make an undirected graph 
        for(auto i:e) 
            graph[i[0]].push_back(i[1]) , graph[i[1]].push_back(i[0]);
        
        queue<int> q;
        vector<bool> seen(n); // for visited nodes and restricted nodes
        
        for(int i: r){ // marking all restricted nodes as seen
            seen[i] = true;
        }
        
        int cnt=0;
        q.push(0);
        seen[0]=true;
        while(q.size()){
            int node= q.front(); 
            q.pop();
            cnt++;
            
            for(auto j:graph[node]) //Put Neighbours
                if(!seen[j]) seen[j]=true , q.push(j);
        }
        return cnt;
    }
    
};