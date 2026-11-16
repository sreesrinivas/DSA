# [1027. Longest Arithmetic Subsequence](https://leetcode.com/problems/longest-arithmetic-subsequence/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array `nums` of integers, return *the length of the longest arithmetic subsequence in* `nums`.

**Note** that:

- A **subsequence** is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

- A sequence `seq` is arithmetic if `seq[i + 1] - seq[i]` are all the same value (for `0 <= i < seq.length - 1`).

 

**Example 1:**

**Input:** nums = [3, 6, 9, 12]

**Output:** 4

**Explanation:** The whole array is already an arithmetic sequence with a common difference of 3, so the longest arithmetic subsequence is `[3, 6, 9, 12]`, of length 4.

**Example 2:**

**Input:** nums = [9, 4, 7, 2, 10]

**Output:** 3

**Explanation:** The longest arithmetic subsequence is `[4, 7, 10]` (indices `1`, `2`, `4`), with a common difference of 3. There is no arithmetic subsequence of length 4.

**Example 3:**

**Input:** nums = [20, 1, 15, 3, 10, 5, 8]

**Output:** 4

**Explanation:** The longest arithmetic subsequence is `[20, 15, 10, 5]` (indices `0`, `2`, `4`, `5`), with a common difference of -5.

 

**Constraints:**

- `2 <= nums.length <= 1500`

- `0 <= nums[i] <= 500`

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
class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return n

        longest = 2
        dp = [{} for _ in range(n)]

        for i in range(n):
            for j in range(i):
                diff = nums[i] - nums[j]
                dp[i][diff] = dp[j].get(diff, 1) + 1
                longest = max(longest, dp[i][diff])

        return longest
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
