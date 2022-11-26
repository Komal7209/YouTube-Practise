class Solution 
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<int> row1(m), row0(m), col1(n), col0(n); 
        
        //row
        int r0, r1;
        for(int i=0; i<m; i++)
        {
            r0=0, r1=0;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==0)
                    r0++;
                else r1++;
                    
            }
            row1[i] = r1;
            row0[i] = r0;
        }
        
        //column
        int c0, c1;
        for(int j=0; j<n; j++)
        {
            c0=0, c1=0;
            for(int i=0; i<m; i++)
            {
                if(grid[i][j]==0)
                    c0++;
                else c1++;
                    
            }
            col1[j] = c1;
            col0[j] = c0;
        }
        
        vector<vector<int>> diff(m, vector<int> (n, 0));
        
        //apply formula
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                diff[i][j] = row1[i] + col1[j] - row0[i] - col0[j];
            }
        }
        
        return diff;
        
    }
};

// tc : O(m*n)
// sc : O(n+m)