import queue


class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        q = queue.Queue()
        q.put(root)
        while not q.empty():
            size = q.qsize()
            x_found = False
            y_found = False
            for i in range(size):
                curr = q.get()
                if curr.val == x:
                    x_found = True
                if curr.val == y:
                    y_found = True
                if curr.left != None and curr.right != None:
                    if (curr.left.val == x and curr.right.val == y) or (curr.left.val == y and curr.right.val == x):
                        return False
                if curr.left != None:
                    q.put(curr.left)
                if curr.right != None:
                    q.put(curr.right)

            if x_found and y_found:
                return True
            if x_found or y_found:
                return False

        return False
