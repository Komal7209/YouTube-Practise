class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
    
        def solve(nums, left, right):
            if left > right: return None
            mid = (left + right) // 2
            root = TreeNode(nums[mid])
            root.left = solve(nums, left, mid - 1)
            root.right = solve(nums, mid+1, right)
            return root
        
        return solve(nums, 0, len(nums) - 1)