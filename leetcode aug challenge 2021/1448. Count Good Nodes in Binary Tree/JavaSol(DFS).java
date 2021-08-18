class Solution {
    public int goodNodes(TreeNode root) {
        
        return rec(root,Integer.MIN_VALUE);
    }
    
    public int rec(TreeNode root, int maxFromRoot){
                // base case of recursion 
        if( root == null) return 0; 
        
        int count = 0;
        
        // if the root value is >= max value till now 
        // we got a one good node, so increase the count 
        // also update the max value which we are going to pass for left and right subtree
        if( root.val >= maxFromRoot){ 
            count++;
            maxFromRoot = root.val;
        }
        
        // recursive call for sub problem 
        count += rec( root.left , maxFromRoot );
        count += rec( root.right , maxFromRoot );
        
        // returning the final ans
        return count;
        
    }
}