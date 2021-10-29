// brute force
/*
- By using 3 loops
and for checking for non duplicate triplets we could directly insert that into the a set

thus overall tc: n^3logm => n size of array , m=>size of set and logm comes from sorting m elements using set
we could use 

*/

// Just next variation to 2 sum problem
// a+b+c =0 => b+c = -a
//Best approach 

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