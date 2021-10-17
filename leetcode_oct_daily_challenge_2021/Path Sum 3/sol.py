class Solution:
    count =0    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        
        def recurse(root, targetsum, must):
            if root == None : return
            if root.val == targetsum: 
                self.count+=1
            if must == False:
                recurse(root.left, targetsum, False)
                recurse(root.right, targetsum, False)

            recurse(root.left, targetsum- root.val,True)
            recurse(root.right, targetsum - root.val, True)
        recurse(root, targetSum, False)
        return self.count
