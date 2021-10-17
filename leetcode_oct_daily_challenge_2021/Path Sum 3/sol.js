var pathSum = function(root, sum) {
    if (!root) return 0;
    return (
      pathSumOnlyStart(root, sum) +
      pathSum(root.left, sum) +
      pathSum(root.right, sum)
    );
  };
  
  const pathSumOnlyStart = (root, sum) => {
    if (!root) return 0;
    const self = root.val === sum ? 1 : 0;
    return (
      self +
      pathSumOnlyStart(root.left, sum - root.val) +
      pathSumOnlyStart(root.right, sum - root.val)
    );
  };