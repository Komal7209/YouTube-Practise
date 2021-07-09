class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = size(A), n = size(B), ans = 0;
        vector<vector<int>>dp(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = A[i-1] == B[j-1] ? dp[i-1][j-1] + 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};