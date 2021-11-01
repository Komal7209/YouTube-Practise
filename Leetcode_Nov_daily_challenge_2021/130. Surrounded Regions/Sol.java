class Solution {
    private int []dx = {0,-1, 1, 0};
    private int []dy = {-1, 0, 0, 1};
    public void solve(char[][] board) {
        
        int rows = board.length;
        if(rows<=2)return;
        int columns = board[0].length;
        if(columns<=2) return;
        
        for(int row =0; row <rows; row++){
            for(int col =0; col<columns; col++){
                if(board[row][col] == 'O' && (row == 0 || col == 0 || row == rows -1 || col == columns -1)){
                    dfs(board, row, col);
                }
            }
        }
        
        for(int row = 0; row<rows; row++){
            for(int col =0; col<columns; col++){
                if(board[row][col] == 'O') board[row][col] = 'X';
                else if(board[row][col] == 'A') board[row][col] = 'O';
            }
        }
    }
    
  public void dfs(char[][] board, int row, int col){
         if(row >=0 && row<board.length && col >= 0 && col<board[0].length && board[row][col] == 'O'){
             board[row][col] = 'A';
         for(int index =0; index<4; index++){
             dfs(board, dx[index]+row , dy[index]+col);
         }
       }
     }
}

