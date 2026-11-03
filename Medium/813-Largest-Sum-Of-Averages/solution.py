class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        if not A or K <= 0:
            return 0.

        n = len(A)
        for i in range(1, n):
            A[i] += A[i - 1]

        dp = [[a / (i + 1) for i, a in enumerate(A)] for _ in range(2)]

        for k in range(1, K):
            for i in range(1, n):
                currRow = k & 1
                prevRow = currRow ^ 1
                v = float('-inf')
                for j in range(0, i):
                    v = max(v, dp[prevRow][j] + (A[i] - A[j]) / (i - j))
                dp[currRow][i] = v

        return dp[(K - 1) & 1][n - 1]
