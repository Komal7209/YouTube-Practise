// we need to find number of ways in which given number could be written

// recursive
// Time: O(2^N), where N <= 100 is length of string s. A char may be decoded alone or by pairing with the next char.
// Space: O(N) // recursive stack

class Solution
{
public:
    int numDecodings(const string &s)
    {
        return recursion(s, 0);
    }
    int recursion(const string &s, int i)
    {
        if (i == s.size())
            return 1;
        int ans = 0;
        if (s[i] != '0') // Single digit
            ans += recursion(s, i + 1);
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) // Two digits
            ans += recursion(s, i + 2);
        return ans;
    }
};
