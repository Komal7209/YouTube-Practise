class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
         if(nums.length == 0) return null;        
        return solve(nums, 0, nums.length-1);
    }
    
    
        TreeNode solve(int[] arr, int start, int end){

        if(start>end) return null;
        int mid = start + (end-start +1)/2;

        TreeNode root = new TreeNode(arr[mid]);

        root.left = solve(arr, start, mid-1);
        root.right = solve(arr, mid+1, end);

        return root;
     } 
    