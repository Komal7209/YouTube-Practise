struct TrieNode
{
    TrieNode *next[26] = {};
    int cnt = 0;
};

class Solution
{
private:
    TrieNode root;

    void insert(string word)
    {
        auto node = &root;
        for (char c : word)
        {
            if (!node->next[c - 'a'])
            {
                node->next[c - 'a'] = new TrieNode();
            }
            node->next[c - 'a']->cnt++;
            node = node->next[c - 'a'];
        }
    }

    int prefixCnt(string s)
    {
        auto node = &root;
        int ans = 0;
        for (char c : s)
        {
            ans += node->next[c - 'a']->cnt;
            node = node->next[c - 'a'];
        }
        return ans;
    }

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {

        // Insert words in trie.
        for (int i = 0; i < words.size(); i++)
        {
            insert(words[i]);
        }
        vector<int> ans(words.size(), 0);

        for (int i = 0; i < words.size(); i++)
        {
            // Get the count of all prefixes of given string.
            ans[i] = prefixCnt(words[i]);
        }
        return ans;
    }
};

