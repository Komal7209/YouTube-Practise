class Solution {
public:
	vector<vector<int>>dp;
	int ans = 0;
	int findLength(vector<int>& A, vector<int>& B) {
		dp.resize(size(A), vector<int>(size(B), -1));
		solve(A, B, 0, 0);
		return ans;
	}
	int solve(vector<int>& A, vector<int>& B, int i, int j) {
		if(i >= size(A) || j >= size(B)) return 0;
		if(dp[i][j] != -1) return dp[i][j];
		solve(A, B, i+1, j), solve(A, B, i, j+1);
		dp[i][j] = A[i] == B[j] ? solve(A, B, i+1, j+1) + 1 : 0;  // store the result for state (i, j) for future
		ans = max(ans, dp[i][j]);
		return dp[i][j];
	}
};	

