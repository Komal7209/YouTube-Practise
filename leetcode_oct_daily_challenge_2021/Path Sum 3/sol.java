class Solution{
    private int count = 0;
    
    public int pathSum(TreeNode root, int targetSum)
        {
            recurse(root, targetSum, false);
            return count;
        }    
    
    void recurse(TreeNode root, int sum, bool must)
        {
            if (root == null) return;
            if (root.val == sum) { count++; }
            if (must == false)
            {  
                recurse(root.left, sum, false);
                recurse(root.right, sum, false);
            }
            
        // below will be called when each node backtrack when base case is hit
            
            recurse(root.left, sum - root.val, true);
            recurse(root.right, sum - root.val, true);
        
     }
}
