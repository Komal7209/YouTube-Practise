class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        if root == None: return 0
        result =0
        
        def findSum(root, pathSum):
            if root == None: return 0
            pathSum = 10*pathSum + root.val
            if root.left == None and root.right == None :
                return pathSum
            return findSum(root.left, pathSum)+findSum(root.right, pathSum)
        
        result = findSum(root, 0)
        return result