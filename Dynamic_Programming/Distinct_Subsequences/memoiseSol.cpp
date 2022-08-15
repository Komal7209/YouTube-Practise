class Solution {
private:
    vector<vector<int>>dp;
    int dfs(string s,int n, string t, int m, vector<vector<int>>&dp){
        
        if(m < 0) return  1;
        if(n<m || n < 0) return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s[n] == t[m])
            return dp[n][m] = dfs(s,n-1,t, m-1, dp) + dfs(s, n-1, t, m, dp);
        else
          return dp[n][m] = dfs(s,n-1, t, m, dp);   
        
    }
public:
    int numDistinct(string s, string t) {
        dp.resize(s.size()+1, vector<int>(t.size()+1, -1));
        return dfs(s, s.size()-1, t, t.size()-1, dp);
    }
};
