class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int rowIndex = 0; // row Index for diagonal
        int colIndex; // col Index for diagonal
        int numberOfDiagonals = r+c-1;
            
        for(int i=1;i<=numberOfDiagonals;++i){
            vector<int> diagonal; // vector for storing diagonal elements
            
            /*
              All the first c diagonals have common starting rowIndex = 0 
              Only colIndex changes
            */
            if(i<=c)
            {
                colIndex = c-i;
            }
            // After that starting colIndex is constant and rowIndex changes
            else
            {
                rowIndex++;
                colIndex = 0;
            }
            
            for(int i=rowIndex,j=colIndex;i<r && j<c;++i,++j)
            {
                diagonal.push_back(mat[i][j]);
            }
            
            sort(diagonal.begin(),diagonal.end());
            
            for(int i=rowIndex,j=colIndex,k=0;i<r && j<c;++i,++j,++k)
            {
               
                mat[i][j] = diagonal[k];
            }
           
        }
        return mat;
    }
};

// TC: O(D*ClogC) // d = r+c-1
// SC: O(R*C)