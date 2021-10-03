class Solution {
    public boolean canJump(int[] nums) {
                
        int maxReach =0;
        
        for( int i =0; i<nums.length; i++){
            if(nums[i]+i >maxReach) maxReach = nums[i]+i;
            if(maxReach == i) break;
        }
        return maxReach>=nums.length-1;
    }
    }
