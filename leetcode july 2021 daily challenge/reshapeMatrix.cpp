class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
       int row = nums.size(), col = nums[0].size(), Order = row * col;
        
        if (r * c != Order) return nums;
        
        vector<vector<int>> res(r, vector<int>(c, 0));
        
        for (int i = 0; i < Order; i++){
            
            res[i / c][i % c] = nums[i / col][i % col];
        }
        
        return res;

        
    }
};

// tc: O(n*m) n->row , m->col
//sc: O(1)
