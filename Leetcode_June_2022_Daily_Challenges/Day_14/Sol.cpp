/*
// TC: O(pow(2, max(m,n)))
// SC: O(max(m,n))
// recursive

class Solution {
private:
    int lcs(string s1, string s2, int m, int n){
        if(m ==0 || n== 0)
            return 0;
        if(s1[m-1] == s2[n-1])
            return 1+ lcs(s1, s2, m-1, n-1);
        else
            return max(lcs(s1, s2, m, n-1) , lcs(s1, s2, m-1, n));
    }
public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2*lcs(word1, word2, word1.size(), word2.size());
    }
};
*/

/*
//TC: O(m*n)
//SC: O(m*n)
// memoised
class Solution {
private:
    int lcs(string s1, string s2, int m, int n, vector<vector<int>>&dp){
        if(m ==0 || n== 0)
            return dp[m][n] =0;
        if(dp[m][n] != -1)
            return dp[m][n];
        if(s1[m-1] == s2[n-1])
            return dp[m][n] = 1+ lcs(s1, s2, m-1, n-1, dp);
        else
            return dp[m][n] = max(lcs(s1, s2, m, n-1, dp) , lcs(s1, s2, m-1, n, dp));
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size()+1, vector<int>(word2.size()+1, -1));
        return word1.size() + word2.size() - 2*lcs(word1, word2, word1.size(), word2.size(), dp);
    }
};
*/

/*
//TC: O(m*n)
//SC: O(m*n)
// bottom up
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1 , vector<int>(word2.size()+1, 0)); // +1 because row and col is completely filled with zero fro make transition statement
        
        for(int i =0; i<=word1.size(); i++){
            for( int j =0; j<=word2.size(); j++){
                
                if( i ==0 || j ==0)
                    continue; // as dp[0][0] is already 0
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1+ dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return word1.size() + word2.size() - 2*dp[word1.size()][word2.size()];
    }
};
*/

//TC: O(m*n)
//SC: O(min(m,n))


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (m < n) swap(word1, word2), swap(n, m);
        vector<int> dpLast(n+1, 0), dpCurr(n+1, 0);
        for (char c1 : word1) { // as we require just to check chars in that string which are common to other string
            for (int j = 0; j < n; j++){ 
                
                if(c1 == word2[j])
                    dpCurr[j+1] = dpLast[j] +1;
                else
                    dpCurr[j+1] = max(dpCurr[j], dpLast[j+1]);
            }
            swap(dpLast, dpCurr);
        }
        return m + n - 2 * dpLast[n];
    }
};