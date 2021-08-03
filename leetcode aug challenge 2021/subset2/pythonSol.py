class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        seen = set()

        for mask in range(1 << n):
            subset = []
            for i in range(n):
                bit = (mask >> i) & 1  
                if bit == 1:
                    subset.append(nums[i])

            seen.add(tuple(subset))

        return seen