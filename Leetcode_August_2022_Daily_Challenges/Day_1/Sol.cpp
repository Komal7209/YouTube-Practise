class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>ans(m, vector<int>(n,1));
        
        for( int i =1; i<m; i++){
            for( int j =1; j<n; j++){
                ans[i][j] =  ans[i-1][j] + ans[i][j-1];
            }
        }
        
        return ans[m-1][n-1];
    }
};