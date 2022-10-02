class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j>0 && j<m-1 && i<n-2){
                    int sum=grid[i][j-1]+grid[i][j]+grid[i][j+1]+grid[i+1][j]+grid[i+2][j-1]+grid[i+2][j]+grid[i+2][j+1];
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};