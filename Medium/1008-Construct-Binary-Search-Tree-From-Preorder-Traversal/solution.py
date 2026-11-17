class Solution:
    def bstFromPreorder(self, preorder):
        return self.createBST(preorder, 0, len(preorder) - 1)

    def createBST(self, pre, st, end):
        if st > end:
            return None

        root = TreeNode(pre[st])

        i = st + 1

        while i <= end and pre[i] < root.val:
            i += 1

        root.left = self.createBST(pre, st + 1, i - 1)
        root.right = self.createBST(pre, i, end)

        return root
