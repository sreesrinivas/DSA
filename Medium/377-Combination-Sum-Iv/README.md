# [377. Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of **distinct** integers `nums` and a target integer `target`, return *the number of possible combinations that add up to* `target`.

The test cases are generated so that the answer can fit in a **32-bit** integer.

 

**Example 1:**

```
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

**Example 2:**

```
Input: nums = [9], target = 3
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 200`

- `1 <= nums[i] <= 1000`

- All the elements of `nums` are **unique**.

- `1 <= target <= 1000`

 

**Follow up:** What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?

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
    def combinationSum4(self, nums, target):
        dp = [1]
        [
            dp.append(sum(dp[i - x] for x in nums if i - x >= 0))
            for i in range(1, target + 1)
        ]
        return dp[-1]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
