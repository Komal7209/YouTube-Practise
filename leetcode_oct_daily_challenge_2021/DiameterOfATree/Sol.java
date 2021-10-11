class Solution {
  private int diameter =0;
    public int height(TreeNode root){
          if(root == null) return 0;
          int leftHeight = height(root.left);
          int rightHeight = height(root.right);
          diameter = Math.max(diameter, leftHeight+rightHeight); // for maintaining max diameter
          return 1+Math.max(leftHeight,rightHeight);
      }
  public int diameterOfBinaryTree(TreeNode root) {
        height(root);
          return diameter;
  }
}