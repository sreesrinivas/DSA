if nums[i] > nums[j]:
    dp[i] = max(dp[i], dp[j] + 1)
