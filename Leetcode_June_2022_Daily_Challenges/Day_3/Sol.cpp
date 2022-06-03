// TC: O(1) for query , for precompuatation: O(mn)
// SC: O(mn)

class NumMatrix {
private:
    vector<vector<int>>dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        
        if(matrix.size() ==0 || matrix[0].size() ==0) return ;
        
        dp.resize(row+1, vector<int>(col+1));
       
        for(int r = 0; r<row; r++){
            for(int c =0; c<col; c++){      
               dp[r+1][c+1] = dp[r+1][c] +dp[r][c+1]+ matrix[r][c] -dp[r][c];                       
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
         return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};