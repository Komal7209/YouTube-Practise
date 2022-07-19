// Time complexity: O(numRows^2) // According to gauss's formula
// Space Complexity: O(1)

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
  
            for (int j = 1; j < i; j++) // 1+ 2+ 3+ 4+...numRows
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        
        return ans;
    }
};