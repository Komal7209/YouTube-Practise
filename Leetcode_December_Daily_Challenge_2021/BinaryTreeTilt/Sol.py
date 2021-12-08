class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        res =0
        def dfs(root):
            nonlocal res
            
            if root == None: return 0
            leftNode = dfs(root.left)
            rightNode = dfs(root.right)
            res += abs(leftNode-rightNode)
            return leftNode + rightNode + root.val
        dfs(root)
        return res