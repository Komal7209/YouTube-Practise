class Solution {
  private int res=0;
   public   int findTilt(TreeNode root) {
          DFS(root);
          return res;
      }
      
      int DFS(TreeNode node) {
          if(node== null) return 0;
          int leftNode=DFS(node.left);
          int rightNode=DFS(node.right);
          res+=Math.abs(leftNode-rightNode);
          return leftNode+rightNode+node.val;
      }
  }