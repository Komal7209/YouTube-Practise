class Solution {
private:
    //vector<vector<int>>dp;
    int dfs(string s,int n, string t, int m){
        
        if(m < 0) return  1; //if we exhausted the string T, then it means we found a subsequence in S that matches T and hence, we return a 1
        if(n<m || n < 0) return 0; //if s string is smaller than t string ans is always 0 or If we exhausted the string S, but there are still characters to be considered in string T, that means we ended up rejecting far too many characters and eventually ran out! Here, we return a 0, now, there's no possibility of a match
        
        if(s[n] == t[m])
            return  dfs(s,n-1,t, m-1) + dfs(s, n-1, t, m); // choosing and not choosing
        else
          return dfs(s,n-1, t, m);    // as character dont match so we just need to move in bigger string
        
    }
public:
    int numDistinct(string s, string t) {
        return dfs(s, s.size()-1, t, t.size()-1);
    }
};