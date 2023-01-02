class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
  
        int n = nums.size();
        if(n<3) return {};
        
        vector<vector<int>>result;
        sort(nums.begin(), nums.end()); // for using two pointer
        
        for(int i =0; i<n-2 ; i++){ // leaving last two element for j and k
            if(i==0 || nums[i]!= nums[i-1]){  // for avoiding duplicates
                int left = i+1, right = n-1;
                
                while(left<right){
                    
                    int sum = nums[i]+nums[left]+ nums[right];
                    if(sum == 0){

                        result.push_back({nums[i],nums[left], nums[right]});
                        while(left<right && nums[left] == nums[left +1]) left++; // for avoiding duplicates
                        while(left<right && nums[right] == nums[right-1]) right--; // for avoiding dupiclates
                        left++;
                        right--;
                    }
                    else if(sum>0) right--;
                    else left++;
                }                   
            }   
        }
       return result; 
    }
};