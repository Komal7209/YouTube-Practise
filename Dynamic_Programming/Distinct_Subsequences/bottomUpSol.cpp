class Solution{
public:

int numDistinct(string s, string t) {
	static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0; i<n; i++) dp[i][0] = 1; // first col of each row 

	for(int i=1; i<=n; i++) // rows
	{ 
		for(int j=1; j<=m; j++) // cols
		{  
			if(s[i-1] == t[j-1])
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%MOD ;
			else 
				dp[i][j] = dp[i-1][j];
		}
      
	}

	return dp[n][m];
}
};

