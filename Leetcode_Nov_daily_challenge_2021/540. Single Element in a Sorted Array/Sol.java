class Solution {
  public int singleNonDuplicate(int[] nums) {
      
      int left =0, right = nums.length-1, mid =0;
      
      while(left<right){
          mid = left + (right - left)/2 ;
          if(((mid%2 == 0) && nums[mid] == nums[mid+1])  || ((mid%2 == 1) && nums[mid-1] == nums[mid]))
              left = mid +1;
          else 
              right = mid;
      }
  return nums[left];    
       
  }
}