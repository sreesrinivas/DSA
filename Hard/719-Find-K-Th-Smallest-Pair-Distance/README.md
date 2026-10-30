# [719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

The **distance of a pair** of integers `a` and `b` is defined as the absolute difference between `a` and `b`.

Given an integer array `nums` and an integer `k`, return *the* `kth` *smallest **distance among all the pairs*** `nums[i]` *and* `nums[j]` *where* `0 <= i < j < nums.length`.

 

**Example 1:**

```
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
```

**Example 2:**

```
Input: nums = [1,1,1], k = 2
Output: 0
```

**Example 3:**

```
Input: nums = [1,6,1], k = 3
Output: 5
```

 

**Constraints:**

- `n == nums.length`

- `2 <= n <= 104`

- `0 <= nums[i] <= 106`

- `1 <= k <= n * (n - 1) / 2`

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
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def enough(distance) -> bool:  # two pointers
            count, i, j = 0, 0, 0
            while i < n or j < n:
                while j < n and nums[j] - nums[i] <= distance:
                    j += 1
                count += j - i - 1
                i += 1
            return count >= k

        nums.sort()
        n = len(nums)
        left, right = 0, nums[-1] - nums[0]
        while left < right:
            mid = left + (right - left) // 2
            if not enough(mid):
                left = mid + 1
            else:
                right = mid
        return left
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
