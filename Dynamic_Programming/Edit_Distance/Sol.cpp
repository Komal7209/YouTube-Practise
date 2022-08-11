class Solution {
private:
    int dfs(string s1, int n, string s2, int m){
        if(n <0) return m+1;
        if(m<0) return n+1;
        
        if(s1[n] == s2[m] )
            return dfs(s1, n-1, s2, m-1);
        else{
            int insertion = dfs(s1, n, s2, m-1);
            int deletion = dfs(s1, n-1, s2, m);
            int replacement =dfs(s1, n-1, s2, m-1);
            
            return 1+ min({insertion, deletion, replacement});
        }
    }
public:
    int minDistance(string word1, string word2) {
      
        return dfs(word1, word1.size()-1, word2, word2.size()-1);
    }
};