class Solution {

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        return dfs(root,targetSum, new ArrayList<Integer>(), new ArrayList<List<Integer>>());
    }
    
    private List<List<Integer>> dfs(TreeNode node,int targetSum,  List<Integer> list, List<List<Integer>> res){
        if(node==null)
            return res;
        
        list.add(node.val);
        
        dfs(node.left, targetSum -  node.val, list, res);
        dfs(node.right,targetSum - node.val, list, res);
        
        if(targetSum == node.val && node.left==null && node.right==null)
            res.add(new ArrayList<Integer>(list));
        
        list.remove(list.size()-1);
        
        return res;
    }
}
