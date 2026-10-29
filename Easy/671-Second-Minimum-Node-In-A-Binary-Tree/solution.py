class Solution(object):
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return -1
        if not root.left and not root.right:
            return -1
        
        t1 = root.left.val
        t2 = root.right.val
        
        if root.left.val == root.val:
            t1 = self.findSecondMinimumValue(root.left)
        if root.right.val == root.val:
            t2 = self.findSecondMinimumValue(root.right)
            
        if t1 == -1 or t2 == -1:
            return -t1*t2
        else:
            return min(t1, t2)
