
// recursive solution
// TC: O(2^n)
// SC: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, INT_MIN);
    }
    int solve(vector<int>& nums, int i, int prev) {
        if(i >= size(nums)) return 0;                                // cant pick any more elements
        int take = 0, dontTake = solve(nums, i + 1, prev);           // try skipping the current element // i+1 indicates updsting index
        if(nums[i] > prev) take = 1 + solve(nums, i + 1, nums[i]);   // or pick it if it is greater than previous picked element
        return max(take, dontTake);                                  // return whichever choice gives max LIS
    }
};


