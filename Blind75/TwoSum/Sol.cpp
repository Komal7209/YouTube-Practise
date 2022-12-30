class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = 0, right = n-1; 
        
        while(left<right){
            if(nums[left] + nums[right] == target) return {left, right};
            if(nums[left]+nums[right] < target)left++;
            else right--;
        }
        
        return {};
    }
};