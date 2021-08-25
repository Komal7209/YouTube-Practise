class Solution {
    long res = 0, total = 0, sub;
    public int maxProduct(TreeNode root) {
        total = subAndSum(root); subAndSum(root);
        return (int)(res % (int)(1e9 + 7));
    }

    private long subAndSum(TreeNode root) {
        if (root == null) return 0;
        sub = root.val + subAndSum(root.left) + subAndSum(root.right);
        res = Math.max(res, sub * (total - sub));
        return sub;
    }
}