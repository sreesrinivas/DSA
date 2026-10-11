class Solution(object):
     def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        if n <= 1:
            return nums
        nums.sort()
        dp = [(0, 0)] * n
        dp[0] = (1, 0)
        maxIndex, maxVal = 0, 1
        for i in range(1, n):
            dp[i] = max((dp[j][0] + 1, j) for j in range(i + 1) if nums[i] % nums[j] is 0)
            if dp[i] > maxVal:
                maxIndex, maxVal = i, dp[i]
        i, lds = maxIndex, [nums[maxIndex]]
        while i != dp[i][1]:
            i = dp[i][1]
            lds.append(nums[i])
        return lds
