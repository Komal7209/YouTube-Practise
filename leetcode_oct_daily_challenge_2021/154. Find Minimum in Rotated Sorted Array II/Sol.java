class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length-1;
        
        while(left<right){
            if(nums[left] <=nums[right])
                right--;
            else
                left++;
        }
        return nums[left];
        
    }
}