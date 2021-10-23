class Solution:
    def findMin(self, nums: List[int]) -> int:
        left, right = 0, len(nums)-1
        while left<right:
            if nums[left]<=nums[right]:
                right-=1
            else:
                left+=1
                
        return nums[left]
        