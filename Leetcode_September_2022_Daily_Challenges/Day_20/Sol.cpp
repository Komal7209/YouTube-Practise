/**
 * dp[i][j] = a[i] == b[j] ? 1 + dp[i + 1][j + 1] : 0;
 * dp[i][j] : max length of common subarray start at a[i] & b[j];
 */
/*

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

*/

/*
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

*/
/*
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
*/
class Solution { // space optimised
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findLength(nums2, nums1); // Make sure len(nums1) > len(nums2) to optimize space
        vector<int> dp(n+1), prevDP(n+1);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[j] =  (nums1[i-1] == nums2[j-1])? prevDP[j-1] + 1 : 0;
                ans = max(ans, dp[j]);
            }
            dp.swap(prevDP);
        }
        return ans;
    }
};
