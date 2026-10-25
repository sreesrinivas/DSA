class Solution:
    def tree2str(self, root: Optional[TreeNode]) -> str:
        if root is None:
            return ""

        if root.left is None and root.right is None:
            return str(root.val)

        left = "(" + self.tree2str(root.left) + ")"

        if root.right is not None:
            right = "(" + self.tree2str(root.right) + ")"
            return str(root.val) + left + right

        return str(root.val) + left
