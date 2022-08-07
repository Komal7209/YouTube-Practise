class Solution {
public:
 int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for (auto& i : s) {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]); // for updating our dp[i] // every character that ends with character j can be used to append this character i, with maximum 1 + DP[j] length(which we are updating in next line with ++dp[i]) .


            res = max(res, ++dp[i]); // for increasing length as we updated
        }
        return res;
    }
};