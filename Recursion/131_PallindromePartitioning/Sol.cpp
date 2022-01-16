class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ret;
        if (s.empty())
            return ret;

        vector<string> path;
        dfs(0, s, path, ret);

        return ret;
    }
    void dfs(int index, string &s, vector<string> &path, vector<vector<string>> &ret)
    {

        if (index == s.size())
        { // base case
            return ret.push_back(path);
        }
        for (int i = index; i < s.size(); ++i)
        { // starting from exactly that position

            if (isPalindrome(s, index, i))
            { // i could take some other value when loop proceeds
                path.push_back(s.substr(index, i - index + 1));
                dfs(i + 1, s, path, ret);
                path.pop_back();
            }
        }
    }
    // for checking pallindrome
    bool isPalindrome(const string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};