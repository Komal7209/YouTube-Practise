class Solution {
 
public:
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return result(dp, n);
    }
    int result(vector<int>&dp, int n){
        if(n<=3) return dp[n] = n;
        if(dp[n]!= -1) return dp[n];
        int count = n;
        
        for( int i=1; i*i<=n; i++){
            count = min(count, 1+ result(dp, n-(i*i)));
        }
        return dp[n]= count;
    }
};