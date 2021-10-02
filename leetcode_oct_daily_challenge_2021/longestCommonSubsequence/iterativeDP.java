class Solution {
  public int longestCommonSubsequence(String str1, String str2) {
      int[][] dp = new int[str1.length() + 1][str2.length() + 1];
      
      for(int i = str1.length() - 1; i >= 0; i--){
          for(int j = str2.length() - 1; j >= 0; j--){
              if(str1.charAt(i) == str2.charAt(j))
                  dp[i][j] = dp[i+1][j+1] + 1;
              else
                  dp[i][j] = Math.max(dp[i+1][j], dp[i][j+1]);
          }
      }
      return dp[0][0];
  }
}