class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxReach =0
        
        for i in range(0, len(nums)):
            if nums[i]+i >maxReach :
                maxReach = nums[i]+i
            if maxReach == i:
                break
                
        return maxReach>= len(nums)-1
        