
// bottom up
// Time: O(N), where N <= 100 is length of string s.
// Space: O(N)

class Solution
{
public:
    int numDecodings(const string &s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] != '0') // Single digit // filling from last for single digits
                dp[i] += dp[i + 1];
            if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) // Two digits
                dp[i] += dp[i + 2];
        }
        return dp[0];
    }
};