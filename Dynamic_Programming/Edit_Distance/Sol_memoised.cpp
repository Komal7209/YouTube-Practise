class Solution {
private:    
    int dfs(string &word1, int n, string &word2, int m, vector<vector<int>>&dp){
        if(n< 0) return m+1; // i.e one word ends thus using other word under insertion operation
        if(m < 0) return n+1;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(word1[n] == word2[m]) 
            return dp[n][m] = dfs(word1, n-1, word2, m-1,dp);
        else{
           // return dp[n][m]= 1+ min({dfs(word1, n-1, word2, m,dp), dfs(word1, n, word2, m-1,dp), dfs(word1, n-1, word2, m-1,dp)});
           int insertion = sub(s1, n, s2, m-1);
            int deletion = sub(s1, n-1, s2, m);
            int substitution = sub(s1, n-1, s2, m-1);
            
            return dp[n][m] = min({insertion, deletion, substitution})+1;
        }
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        return  dfs(word1, word1.size()-1, word2, word2.size()-1 , dp);
    }
};