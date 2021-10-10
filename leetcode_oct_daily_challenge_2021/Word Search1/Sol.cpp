class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {

        // initiating for checking for whole matrix
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) // here 0 is count in given word
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, int count, string word)
    {
        if (count == word.size()) // if word size has been reached
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[count])
            //checking for boundaries and change of chars
            return false;
        char temp = board[i][j];
        board[i][j] = '0';                                     // for marking that we have visited this box
        bool found = dfs(board, i + 1, j, count + 1, word)     //left
                     || dfs(board, i - 1, j, count + 1, word)  //right
                     || dfs(board, i, j - 1, count + 1, word)  //up
                     || dfs(board, i, j + 1, count + 1, word); //down
                                                             
        board[i][j] = temp;                                    // backtracking
                                                              
        return found;
    }
};