class Solution(object):
    def maxProduct(self, root):
        self.res = total = 0

        def subAndSum(root):
            if not root:
                return 0
            left, right = subAndSum(root.left), subAndSum(root.right)
            self.res = max(self.res, left * (total - left),
                           right * (total - right))
            return left + right + root.val

        total = subAndSum(root)
        subAndSum(root)
        return self.res % (10**9 + 7)
