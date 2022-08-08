// TC:O(n^2)
// SC: O(n)

// tabulation method

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = size(nums);
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < i; j++) 
                if(nums[i] > nums[j]) 
				    dp[i] = max(dp[i], dp[j] + 1), ans = max(ans, dp[i]); // nums[j]+1 => denotes smaller element that nums[i]
                                                                          // dp[i] =... => represents max length till now
        
        return ans;
    }
};


