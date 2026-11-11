# [945. Minimum Increment to Make Array Unique](https://leetcode.com/problems/minimum-increment-to-make-array-unique/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums`. In one move, you can pick an index `i` where `0 <= i < nums.length` and increment `nums[i]` by `1`.

Return *the minimum number of moves to make every value in *`nums`* **unique***.

The test cases are generated so that the answer fits in a 32-bit integer.

 

**Example 1:**

```
Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
```

**Example 2:**

```
Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
```

 

**Constraints:**

- `1 <= nums.length <= 105`

- `0 <= nums[i] <= 105`

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution(object):
    def minIncrementForUnique(self, nums):
        nums.sort()
        ans = 0
        for i in range(1, len(nums)):
            if nums[i] <= nums[i - 1]:
                ans += nums[i - 1] - nums[i] + 1
                nums[i] = nums[i - 1] + 1
        return ans
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
