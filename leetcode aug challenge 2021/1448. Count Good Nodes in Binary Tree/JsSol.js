var goodNodes = function(root) {
    let count = 0
    function dfs(node, max){
      if(!node) return 
      if(node.val >= max)
        count++
      max = Math.max(max, node.val)
      dfs(node.left, max)
      dfs(node.right, max)
    }
    dfs(root, -Infinity)
    return count
  }