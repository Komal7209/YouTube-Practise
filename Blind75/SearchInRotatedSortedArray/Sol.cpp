
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            
            int mid = left + (right-left)/2;
            
            // if there is no rotation
            if (target == nums[mid])
                return mid;
            
            //   5 6 7 > 1 2 3 4  =>t = 6 , nums[left] = 5
            // there exists rotation; the middle element is in the left part of the array// means ans could be in left side
            if (nums[mid] > nums[right]) {  // if not rotated then nums[mid] would have been smaller than nums[right], thus now smaller elements are at right        
                //as it is sorted so if target is there then it will be less than mid and greater than or equal to left 
                if (target < nums[mid] && target >= nums[left]) // range thus need to make right inside left most search space
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            
            //   5 6 7 1 2 < 3 4  =>t = 3 , nums[right] = 4
            // there exists rotation; the middle element is in the right part of the array
            else if (nums[mid] < nums[left]) {
                // as sorted thus target would be surely greater than mid and less than or equal to right
                if (target > nums[mid] && target <= nums[right]) // range thus need to make right inside right most search space
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            
            // there is no rotation; just like normal binary search
            else {
                if (target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};
