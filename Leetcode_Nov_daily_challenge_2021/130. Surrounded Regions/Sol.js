// Editorial Link: https://leetcode.com/problems/surrounded-regions/discuss/1553456/JavaScript-81-fast-or-86-less-memory-DFS-solution
//PS: I hadnt converted to javascript here, so I have attached discuss link, I'll modify when I'll convert my cpp code to javascript
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    const toVisit = [];
    const m = board.length;
    const n = board[0].length;
    
    // identify all 'O's at the edges of board.
    // A region cannot be captured only if it is connected to atleast one of the edges
    
    // first and last row
    for (let i = 0; i < n; i += 1) {
        if (board[0][i] === 'O') toVisit.push({ x: 0, y: i });
        if (board[m - 1][i] === 'O') toVisit.push({ x: m - 1, y: i });
    }
    // first and last column
    for (let i = 0; i < m; i += 1) {
        if (board[i][0] === 'O') toVisit.push({ x: i, y: 0 });
        if (board[i][n - 1] === 'O') toVisit.push({ x: i, y: n - 1 });
    }
    
    // perform DFS using the edge cells to identify all the cells connected to them
    // these are the cells that cannot be captured. mark them as CNC (Can Not Capture)
    while (toVisit.length > 0) {
        const cell = toVisit.pop();
        board[cell.x][cell.y] = 'CNC';
        
        if (cell.x + 1 < m && board[cell.x + 1][cell.y] === 'O')
            toVisit.push({ x: cell.x + 1, y: cell.y });
        if (cell.x - 1 >= 0 && board[cell.x - 1][cell.y] === 'O')
            toVisit.push({ x: cell.x - 1, y: cell.y });
        if (cell.y + 1 < n && board[cell.x][cell.y + 1] === 'O')
            toVisit.push({ x: cell.x, y: cell.y + 1 });
        if (cell.y - 1 >= 0 && board[cell.x][cell.y - 1] === 'O')
            toVisit.push({ x: cell.x, y: cell.y - 1 });
    }
    
    // iterate through the cells in the board
    // convert remaining 'O' cells to 'X'. These cells are not connected to edge cells and are thus captured.
    // revert 'CNC' cells to 'O'
    for (let i = 0; i < m; i += 1) {
        for (let j = 0; j < n; j += 1) {
            if (board[i][j] === 'O') board[i][j] = 'X';
            if (board[i][j] === 'CNC') board[i][j] = 'O';
        }
    }
};