class Solution {
    private int result;
    public int sumNumbers(TreeNode root) {
       if(root == null) return 0;
        result =0;
        findSum(root, 0);
        return result;
    }
    
    void findSum(TreeNode root, int val){
        int curr = val*10 + root.val;
        if(root.left ==null && root.right ==null){ //leaf root
            result += curr;
            return;
        }
    if(root.left !=null) findSum(root.left, curr);
    if(root.right !=null) findSum(root.right, curr);
    }
}