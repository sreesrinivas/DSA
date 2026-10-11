class Solution(object):
    def combinationSum4(self, nums, target):
        dp = [1]
        [
            dp.append(sum(dp[i - x] for x in nums if i - x >= 0))
            for i in range(1, target + 1)
        ]
        return dp[-1]
