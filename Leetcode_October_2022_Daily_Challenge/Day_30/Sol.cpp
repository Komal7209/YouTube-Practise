class Solution {
private:
    
    vector<int>dx = {0,1,-1,0};
    vector<int>dy = {-1,0,0,1};
    
    bool isNotValid(int x, int y, vector<vector<int>>&grid)
    {
        return x<0 || y<0 || x>=grid.size() || y>=grid[0].size();              
    }
    
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),-1));// for keeping track of obstacle removed from that cell or not, else we would have been required to modify the original matrix
        queue<vector<int>> q;
		
		// queue stores (x,y,current path length,number of obstacles we can still remove)
        q.push({0,0,0,k});
        while(!q.empty())
        {
         // processing of front of q starts
            vector<int>t= q.front();
            int x=t[0],y=t[1];
            q.pop();
			
			// out of matrix boundaries then check for next coordinates in queue
            if (isNotValid(x, y, grid)) continue;
			
			// Destination found
            if(x==grid.size()-1 && y==grid[0].size()-1)
                return t[2]; // as 2nd index has path stored

            if(grid[x][y]==1) //obstacle found
            {
                if(t[3]>0) // we still have limit to remove obstacles
                    t[3]--;
                else
                    continue; // we no more can remove obtacle thus now figure out if we can 
            }
			
			// The cell was previously visited by some path and we were able to remove more obstacles from the previous path.
			// Then we don't need to continue on our current path
            if(vis[x][y]!=-1 && vis[x][y]>=t[3])
                continue;
            vis[x][y]=t[3]; // chance of removing obstacle left or not
            
            // for checking in all 4 directions
            for( int i =0; i<4; i++)
            {
             q.push({x+dx[i],y+dy[i],t[2]+1,t[3]});
            }
         
        }
        return -1;
    }
};