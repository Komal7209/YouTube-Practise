class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>valid(n, false);
        
        // for array of length 2
        if(nums[1]==nums[0]) valid[1] = true;
        if(n==2) return valid[1];
        
        // for array of length 3
        if(nums[2]==nums[1] && nums[1]==nums[0]) valid[2] = true; // when all equal
        if(nums[2]==nums[1]+1 && nums[1]==nums[0]+1) valid[2] = true; // when in increasing order
        if(n==3) return valid[2];
        
        // for array above 3 length
        for(int i=3; i<n; i++){
            if(nums[i]==nums[i-1] && valid[i-2]) valid[i] = true; // for 2 equal and were previous valid till now
            if(nums[i]==nums[i-1] && nums[i-1]==nums[i-2] && valid[i-3]) valid[i] = true; // for 3 equal and were previous valid till now
            if(nums[i]==nums[i-1]+1 && nums[i-1]==nums[i-2]+1 && valid[i-3]) valid[i] = true; // for increasing order sequence
        }
        return valid[n-1]; // as n would be valid if n-1 is already valid
    }
};