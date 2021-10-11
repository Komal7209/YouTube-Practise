class Solution:
    def diameterOfBinaryTree(self,root):
        self.diameter = 0
        def height(root):
            if not root: return 0
            leftHeight = height(root.left)
            rightHeight = height(root.right)
            self.diameter = max(self.diameter, leftHeight + rightHeight)
            return 1 + max(leftHeight,rightHeight)
        
        height(root)
        return self.diameter