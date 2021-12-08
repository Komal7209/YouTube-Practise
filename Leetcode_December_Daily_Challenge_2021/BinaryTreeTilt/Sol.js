var findTilt = function (root) {
  var res = 0;
  var DFS = function (node) {
    if (node == null) return 0;
    var leftNode = DFS(node.left);
    var rightNode = DFS(node.right);
    res += Math.abs(leftNode - rightNode);
    return leftNode + rightNode + node.val;
  }

  DFS(root);
  return res;
};