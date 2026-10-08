class Solution:
    # DP
    # Time: O(n(sqrt(n)))
    # Space O(n)
    def numSquares(self, n: int) -> int:
        # dp[i]: number of perfect square that sum to n
        # The first perfect square is 1
        dp = [i for i in range(n+1)]
        
        # The second perfect square is 4. Which is 2*2.
        # We go from there
        # Array with all perfect squares in the range (4, sqrt(n))
        squares = [i**2 for i in range(2, n) if i**2 <= n]
       
        for square in squares:
            for i in range(square, n+1):
                dp[i] = min(dp[i-square] + 1, dp[i])
            
        return dp[-1]
