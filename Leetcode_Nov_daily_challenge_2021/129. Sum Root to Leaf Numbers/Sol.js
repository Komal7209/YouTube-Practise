const helper = (node, sum) => {
    if (!node) return 0;
    const newSum = sum * 10 + node.val;
    if (!node.left && !node.right) return newSum;
    return helper(node.left, newSum) + helper(node.right, newSum);
  };
  
  var sumNumbers = function (root) {
    return helper(root, 0);
  };