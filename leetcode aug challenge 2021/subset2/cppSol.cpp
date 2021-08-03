class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>>seen;
  
        int n = nums.size();
        
        for(int counter =0; counter< (1<<n) ; counter++){  // counter is from 0 to pow(2, n) -1
             vector<int>temp;
            for( int j =0; j<n; j++){
                if((counter&(1<<j))!=0)
                    temp.push_back(nums[j]);
            }
              
            if(!seen.count(temp)){
               ans.push_back(temp); 
                seen.insert(temp);
        }
    }
        
       return ans; 
    }
};