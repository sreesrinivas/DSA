# [368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a set of **distinct** positive integers `nums`, return the largest subset `answer` such that every pair `(answer[i], answer[j])` of elements in this subset satisfies:

- `answer[i] % answer[j] == 0`, or

- `answer[j] % answer[i] == 0`

If there are multiple solutions, return any of them.

 

**Example 1:**

```
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```

**Example 2:**

```
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```

 

**Constraints:**

- `1 <= nums.length <= 1000`

- `1 <= nums[i] <= 2 * 109`

- All the integers in `nums` are **unique**.

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
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
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
