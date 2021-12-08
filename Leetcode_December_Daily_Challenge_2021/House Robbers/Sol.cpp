/*
//Recursive Solution:

class Solution {
public:
    
    int sub(vector<int>&nums, int index){
        
        if(index>=nums.size()) return 0;  // base case
		
		// we have two options
        
//         int robThis = sub(nums, index+2) + nums[index];
//         int dont = sub(nums, index+1);
        int robThis,dont;

        robThis = sub(nums, index+2) + nums[index];
  
        dont = sub(nums, index+1);
        
        return max(dont, robThis);
        
    }
    
    int rob(vector<int>& nums) {
        
        return sub(nums, 0);
    }
};
*/

/*
// memoised recursive code
class Solution {
public:
    
    vector<int>dp;
    int sub(vector<int>&nums, int index){
        
        if(index>=nums.size()) return 0;      // base case
        if(dp[index] != -1) return dp[index]; // so that repeatedly calculation is avoided
        
       
        int robThis = sub(nums, index+2) + nums[index];
  
        int dont = sub(nums, index+1);
        
        return dp[index] = max(dont, robThis);
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return sub(nums, 0);
    }
};
*/


class Solution {
public:
    
       int rob(vector<int>& nums) {
           
          vector<int>dp(nums.size());
           
           dp[0] = nums[0];
           if(nums.size() == 1) return dp[0];           
           dp[1] = max(nums[0], nums[1]);
           
           for( int i =2; i<nums.size(); i++){
               
               
               int robthis = dp[i-2] + nums[i];
               int dont = dp[i-1];
               
               dp[i] = max(robthis, dont);
           }
           
           return dp[nums.size()-1];
           
       }
};

