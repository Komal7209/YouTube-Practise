//bfs

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
         List<List<Integer>> res = new LinkedList<>();
         Queue<Node>q = new LinkedList<Node>();
        
        if(root == null) return res;
        q.add(root);
        
        while(!q.isEmpty()){
            
            Integer size = q.size();
            List<Integer>currLevel = new LinkedList<Integer>();
            
            for( int i=0; i<size;i++){
                
                Node currNode = q.poll();
                        
                currLevel.add(currNode.val);
                for(Node n: currNode.children)
                    q.add(n);
            }
            res.add(currLevel);
        }
        return res;       
    }
}