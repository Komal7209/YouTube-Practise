class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxx = INT_MIN;
        
        unordered_map<int, int>mp;
        for( auto i: nums)
        { mp[i]++;
        }

        
       for( int i =0; i<nums.size(); i++)
       {
         if(mp.count(0-nums[i]))
        {
            maxx = max(nums[i], maxx);
        }
                
       }
        
    int ans = -1;
        if(maxx != INT_MIN) ans = maxx;
        
        return ans;
    }
};