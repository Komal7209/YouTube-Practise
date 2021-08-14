
        
        // this solution requires costly memory so we need to optimise this 
        // moreover it takes two passes to solve the ques
        //tc: m*n as it is matrix
        // sc: m+n as two new vectors are used
        
        class Solution {
            public void setZeroes(int[][] matrix) {
            int H = matrix.length;
            int W = matrix[0].length;
            Boolean[] row_zero = new Boolean[H];
            Boolean[] column_zero = new Boolean[W];
            for(int row =0; row< H; ++row){
                for(int col = 0; col< W; ++col){
                    if(matrix[row][col] == 0){
                        row_zero[row] = true; // assigning true , false to new vectors as per zero encounter
                        column_zero[col] = true;
                    }
                }
            }
            
            // in this step we get col no. and row no. from aux vectors to set matrix as 0 in that row or col
            for(int row = 0; row<H; ++row){
                for(int col = 0; col< W; ++col){
                    if(row_zero[row]== true || column_zero[col] == true){ // i.e if they are true 
                        matrix[row][col] = 0;
                    }
                }
            }
            
        }
    }
    