# https://leetcode.com/problems/surrounded-regions/discuss/1552959/C%2B%2BPython-Interview-friendly-recursive-DFS
#PS: I hadnt converted to python here, so I have attached discuss link, I'll modify when I'll convert my cpp code to python

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m = len(board)
        n = len(board[0])
        if m <= 2 or n <= 2:
            return;
    
        def markBorder(i, j):
            if 0 <= i < m and 0 <= j < n and board[i][j] is 'O':
                board[i][j] = 'B'
                markBorder(i + 1, j)
                markBorder(i - 1, j)
                markBorder(i, j + 1)
                markBorder(i, j - 1)

        for i in range(m):
            markBorder(i, 0)
            markBorder(i, n - 1)

        for j in range(n):
            markBorder(0, j)
            markBorder(m - 1, j)

        for i in range(m):
            for j in range(n):
                c = board[i][j]
                if c is not 'X':
                    board[i][j] = 'X' if c is 'O' else 'O'