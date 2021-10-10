class TrieNode
{
public:
    // bool is_end;
    string word;
    vector<TrieNode *> children;
    TrieNode()
    {
        // is_end = false;
        children = vector<TrieNode *>(26, NULL);
    }
};

class Solution
{
private:
    TrieNode *root; // creation of object of trienode class

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = buildTrie(words);
        vector<string> result;

        // initiating for checking whole matrix by dfs
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words)
    {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++) // traversing words vector
        {
            string word = words[j];                 // taking one word from words vector
            TrieNode *curr = root;                  // start from root
            for (int i = 0; i < word.length(); i++) // for insertion of word into trie char by char
            {
                char index = word[i] - 'a';           // getting index
                if (curr->children[index] == nullptr) // i.e the initial stage
                {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index]; // update position of curr
            }
            curr->word = word; // update word // rather than marking true or false , we are updating the string at end of word complete
        }
        // when all words are added, then return root
        return root;
    }

    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *p, vector<string> &result)
    {
        char c = board[i][j];
        if (c == '#' || !p->children[c - 'a'])
            return;
        p = p->children[c - 'a'];
        if (p->word.size() > 0)
        {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#'; // marking visited
        if (i > 0)
            dfs(board, i - 1, j, p, result);
        if (j > 0)
            dfs(board, i, j - 1, p, result);
        if (i < board.size() - 1)
            dfs(board, i + 1, j, p, result);
        if (j < board[0].size() - 1)
            dfs(board, i, j + 1, p, result);
        board[i][j] = c; // backtracking
    }
};