class Solution {
public:
    int findMin(vector<int>& nums) {
        
        // edge cases (when there is no rotation and when only 1 element is there)
        if(nums.size() == 1 or nums[0] < nums[nums.size()-1])
             return nums[0];
                 
        int left = 0 , right = nums.size()-1 ;
            while(left <= right){
               int mid = left + (right - left) ;// 2
                if(mid > 0 and nums[mid - 1] > nums[mid]) // # The nums[mid] is the minimum number when previous element is bigger than mid
                    return nums[mid];
                if(nums[mid] > nums[right]) // # search on the right side, because smaller elements are in the right side
                    left = mid + 1;
                else
                    right = mid - 1 ;      // # search the minimum in the left side
        }
        return INT_MIN; // or we could put return nums[0] as it will cover above edge casez
    }
};