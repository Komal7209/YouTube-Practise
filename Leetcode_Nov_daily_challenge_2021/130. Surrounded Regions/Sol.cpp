class Solution
{
private:
    vector<int> dx = {0, -1, 1, 0};
    vector<int> dy = {-1, 0, 0, 1};

public:
    void solve(vector<vector<char>> &board)
    {

        int rows = board.size();
        if (rows <= 2)
            return;
        int columns = board[0].size();
        if (columns <= 2)
            return;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < columns; col++)
            {
                if (board[row][col] == 'O' and (row == 0 || col == 0 || row == rows - 1 || col == columns - 1))
                {
                    dfs(board, row, col);
                }
            }
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < columns; col++)
            {
                if (board[row][col] == 'O')
                    board[row][col] = 'X';
                else if (board[row][col] == 'A')
                    board[row][col] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int row, int col)
    {
        if (row >= 0 and row < board.size() and col >= 0 and col < board[0].size() and board[row][col] == 'O')
        {
            board[row][col] = 'A';
            for (int index = 0; index < 4; index++)
            {
                dfs(board, dx[index] + row, dy[index] + col);
            }
        }
    }
};