//TC: O(n)
//SC:O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size(), missing_num = n;
        
        
        for(int i =0; i<n; i++){
            missing_num ^= i^nums[i];
        }
        
        return missing_num; 
    }
};