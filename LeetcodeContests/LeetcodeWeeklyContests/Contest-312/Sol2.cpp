
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = INT_MIN, length = 0,ans =0;
        
        for( int num: nums)
        {
            maxNum = max(maxNum, num);
        }
        
        for( int num: nums){
            if(num== maxNum)
            {
                length++;
            }
            else
            {
                length =0;
            }
            ans = max(length, ans);
        }
        
        return ans;
        
    }
};