class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        left , right, mid =0, len(nums)-1, 0
        
        while left<right :
            mid = (left + right)//2
            if(((mid%2 == 0) and nums[mid] == nums[mid+1])  or ((mid%2 == 1) and nums[mid-1] == nums[mid])):
                left = mid +1
            else: 
                right = mid
                
        return nums[left]