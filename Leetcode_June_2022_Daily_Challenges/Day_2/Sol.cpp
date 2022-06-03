class Solution {
public:

    vector<vector<int>> transpose(vector<vector<int>> A) {
        int row = A.size(), col = A[0].size();
        vector<vector<int>> B(col, vector<int>(row, 0));
        for (int j = 0; j < col; j++)
            for (int i = 0; i < row; i++)
                B[j][i] = A[i][j];
        return B;
    }
};