/*
// unordered_map or frequency vector solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int>mp;
        
        for(int i : nums){
            mp[i]++;
        }
        
        for(auto i: mp){
            if(i.second == 1) return i.first;
        }
        return -1;
    }
};
*/

// XOR Solution

/*
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int ans =0;
        
        for(int i : nums){
            ans^=i;
        }
        return ans;
    }
};

*/



// binary search approach

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    
        int left =0, right = nums.size()-1, mid =0;
        
        while(left<right){
            mid = left + (right - left)/2 ;
            if(((mid%2 == 0) and nums[mid] == nums[mid+1])  or ((mid%2 == 1) and nums[mid-1] == nums[mid]))
                left = mid +1;
            else 
                right = mid;
        }
    return nums[left];    
    }    
};
