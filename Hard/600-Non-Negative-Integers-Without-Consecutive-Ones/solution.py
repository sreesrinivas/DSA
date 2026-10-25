class Solution:
    def findIntegers(self, n: int) -> int:
        dp = [0] * 32

        dp[0] = 1
        dp[1] = 2

        for i in range(2, 32):
            dp[i] = dp[i - 1] + dp[i - 2]

        ans = 0
        prev_bit = 0

        for i in range(30, -1, -1):
            if n & (1 << i):
                # Put 0 instead of 1 at this position.
                # The remaining i bits have dp[i] valid combinations.
                ans += dp[i]

                # n contains consecutive 1s, so n itself is invalid.
                if prev_bit == 1:
                    return ans

                prev_bit = 1
            else:
                prev_bit = 0

        # n itself is valid.
        return ans + 1
