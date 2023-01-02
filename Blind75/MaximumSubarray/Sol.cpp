class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //kadane's algo
        
        if(nums.size() == 0 )
            return 0;
        
        int sum_max = nums[0];  // initialising with first element of array
        int sum_including_current = nums[0];  // initialising with first element of array
        
        for(int i =1 ; i < nums.size(); ++i){
            int current = nums[i];
            sum_including_current = max(sum_including_current + current, current );
            sum_max = max(sum_max, sum_including_current);
        }
        return sum_max;
        
    }
};