class Solution:
    def solve(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        if n == 1:
            self.dp[1] = [TreeNode()]
            return self.dp[1]
        if len(self.dp[n]) > 0:
            return self.dp[n]
        ans = []
        for i in range(1, n, 2):
            Left = self.solve(i)
            Right = self.solve(n - 1 - i)
            for l in Left:
                for r in Right:
                    root = TreeNode()
                    root.left = l
                    root.right = r
                    ans.append(root)
        self.dp[n] = ans
        return ans

    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        self.dp = [[] for _ in range(n + 1)]
        return self.solve(n)
