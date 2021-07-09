class Solution {
public:
	int ans = 0;
	int findLength(vector<int>& A, vector<int>& B) {
		solve(A, B, 0, 0);
		return ans;
	}
	int solve(vector<int>& A, vector<int>& B, int i, int j) {
		if(i >= A.size()) || j >= B.size()) return 0;
		solve(A, B, i+1, j), solve(A, B, i, j+1);                   // recurse to solve for each possible (i, j)
		int common = A[i] == B[j] ? 1 + solve(A, B, i+1, j+1) : 0;  // longest common subarray starting at A[i] & B[j]
		ans = max(ans, common);                                     // update ans to hold max length found till now
		return common;
	}
};


