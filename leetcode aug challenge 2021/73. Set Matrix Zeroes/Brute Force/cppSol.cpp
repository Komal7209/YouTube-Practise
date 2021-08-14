class Solution
{
public:
    // this solution requires costly memory so we need to optimise this
    // moreover it takes two passes to solve the ques
    //tc: m*n as it is matrix
    // sc: m+n as two new vectors are used

    void setZeroes(vector<vector<int>> &matrix)
    {
        const int H = matrix.size();
        const int W = matrix[0].size();
        vector<bool> row_zero(H);    // bool[h]
        vector<bool> column_zero(W); //bool[W]
        for (int row = 0; row < H; ++row)
        {
            for (int col = 0; col < W; ++col)
            {
                if (matrix[row][col] == 0)
                {
                    row_zero[row] = true; // assigning true , false to new vectors as per zero encounter
                    column_zero[col] = true;
                }
            }
        }

        // in this step we get col no. and row no. from aux vectors to set matrix as 0 in that row or col
        for (int row = 0; row < H; ++row)
        {
            for (int col = 0; col < W; ++col)
            {
                if (row_zero[row] || column_zero[col])
                { // i.e if they are true
                    matrix[row][col] = 0;
                }
            }
        }
    }
};
