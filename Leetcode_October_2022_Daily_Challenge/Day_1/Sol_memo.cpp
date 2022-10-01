// memoised
// Time: O(N), where N <= 100 is length of string s.
// Space: O(N)

class Solution
{
private:
    vector<int> memo;

public:
    int numDecodings(const string &s)
    {
        memo.resize(100, -1);
        return dp(s, 0);
    }
    int dp(const string &s, int i)
    {
        if (i == s.size())
            return 1;
        if (memo[i] != -1)
            return memo[i];
        int ans = 0;
        if (s[i] != '0') // Single digit
            ans += dp(s, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) // Two digits
            ans += dp(s, i + 2);
        return memo[i] = ans;
    }
};
