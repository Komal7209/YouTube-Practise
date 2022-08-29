// TC: O(m*n)
// SC: O(m*n)


//bfs 

// here we have used visited map so that we dont change all 1 to 0 i.e board remains as it is
class Solution {
private:

    int dx[4]={-1,0,0,1};
    int dy[4]={0,-1,1,0};
    
    bool isvalid(int i, int j, vector<vector<char>>&grid, int n, int m)
  {
   return (i>=0 && i<=n-1 && j>=0 && j<=m-1 && grid[i][j]=='1'); // these all are true conditions thats why and is there in between
  }
    
    void bfs(vector<vector<char>>&grid, int n, int m, int i, int j, map<pair<int, int>,int>&vis)//by reference passing syntax
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int f=q.front().first; // x coordinate of cell
            int s=q.front().second; // y coordinate of cell
            q.pop();
            for(int k=0;k<4;k++) // for moving in 4 directions of a cell
            {
                int new_x=f+dx[k];
                int new_y=s+dy[k];
                if(isvalid(new_x, new_y,grid, n,m) && !vis[{new_x,new_y}])
                {
                    vis[{new_x,new_y}]=1;
                    q.push({new_x,new_y});           
                }
            }
        }
    }
    
public:     
    int numIslands(vector<vector<char>>& grid) {
        
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();
        map<pair<int, int>,int>vis; // syntax of pair of map
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!vis[{i,j}] && grid[i][j]=='1')// usage syntax
                {
                     islands++;
                    bfs(grid,n,m,i,j,vis); // calling this bfs to erase all connected islands to this '1'

                }
            }
        }
        
        return islands;        
    }
};