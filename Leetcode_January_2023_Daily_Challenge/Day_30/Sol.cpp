// class Solution {
// public:
//     int tribonacci(int n) {
//       if(n==0) return 0;
//        else if(n==1) return 1;
//        else if(n==2) return 1;
//         return tribonacci(n-1)+ tribonacci(n-2)+ tribonacci(n-3);
//     }
// };
// // tc: O(Pow(3,n))
// // sc: O(n)



// tc: O(n)
// sc: O(n)
// class Solution {
// public:
//     int dp[40];
//     int solve(int n)
//     {
//         if(n<=1)
//             dp[n]=n;
//         if(n==2)
//             dp[2]=1;
//         if(dp[n]!=-1)
//                return dp[n];
//         return dp[n]=solve(n-1)+solve(n-2)+solve(n-3);
//     }
//     int tribonacci(int n) {
//         memset(dp,-1,sizeof(dp));
//         int ans=solve(n);
//         return ans;
//     }
// };


// tc: O(n)
// sc: O(n)
class Solution {
public:
    int tribonacci(int n) {
        int dp[n+1];
        if(n == 0 || n ==1) return n;
        if(n==2) return 1;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};
