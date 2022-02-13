class Solution {
public:    
    vector<vector<int>> subsets(vector<int>& nums) {
       
        int n = nums.size();
        vector<vector<int>>ans(1<<n);        
        int powerSize = pow(2,n); 
        
        
        for( int counter =0; counter < powerSize; counter++){
            for(int i =0; i<n; i++){
                if((counter & (1<<i)) != 0) // if ith bit is set 
                   ans[counter].push_back(nums[i]);
            }   
        }
        return ans;      
        
    }
};