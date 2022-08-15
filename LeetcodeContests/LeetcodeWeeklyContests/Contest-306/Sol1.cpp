class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int> (n-2,0));
        
        
        // find the max for each center value
        // and store it in (i-1)(j-1)
        for(int i=1;i<=n-2;i++)
        {
            for(int j=1;j<=n-2;j++)
            {
                int mx = INT_MIN;
                mx = max(mx,max(grid[i-1][j-1],max(grid[i-1][j],grid[i-1][j+1])));    // (0,0)(0,1)(0,2)
                mx = max(mx,max(grid[i][j-1],max(grid[i][j],grid[i][j+1])));          // (1,0)(1,1)(1,2)
                mx = max(mx,max(grid[i+1][j-1],max(grid[i+1][j],grid[i+1][j+1])));    // (2,0)(2,1)(2,2)
                
                ans[i-1][j-1]=mx;
            }
        }
        return ans;
    }
};