# [813. Largest Sum of Averages](https://leetcode.com/problems/largest-sum-of-averages/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums` and an integer `k`. You can partition the array into **at most** `k` non-empty adjacent subarrays. The **score** of a partition is the sum of the averages of each subarray.

Note that the partition must use every integer in `nums`, and that the score is not necessarily an integer.

Return *the maximum **score** you can achieve of all the possible partitions*. Answers within `10-6` of the actual answer will be accepted.

 

**Example 1:**

```
Input: nums = [9,1,2,3,9], k = 3
Output: 20.00000
Explanation: 
The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
```

**Example 2:**

```
Input: nums = [1,2,3,4,5,6,7], k = 4
Output: 20.50000
```

 

**Constraints:**

- `1 <= nums.length <= 100`

- `1 <= nums[i] <= 104`

- `1 <= k <= nums.length`

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
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
