// TC: O(m*n)
// SC: O(m*n)



// dfs 
// here board is being changed because we are converting all 1 to 0

class Solution {
private:
    vector<int>dx = {0, 0, -1, 1};
    vector<int>dy = {1, -1, 0, 0};
    
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0'; // this removes all islands
        for(int dir =0; dir<4; dir++){
            int x = dx[dir]+i; // i gives cell position + dx[dir] gives x axis direction
            int y = dy[dir]+j;
            
            eraseIslands(grid, x, y);
        }/
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    eraseIslands(grid, i, j);//so that all connected '1's in all 4 direction to this '1' are removed
                }
            }
        }
        return islands;
    }
};

