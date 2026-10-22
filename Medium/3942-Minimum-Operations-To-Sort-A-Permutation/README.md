# [3942. Minimum Operations to Sort a Permutation](https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums` of length `n`, where `nums` is a permutation of the integers from 0 to `n - 1`.

You may perform **only** the following operations:

- **Reverse** the entire array.

- **Rotate Left by One**: Move the first element to the end of the array, and rest elements to left by one position.

Return an integer denoting the **minimum** number of operations required to sort the array in **increasing** order. If it is **not possible** to sort the array using only the given operations, return -1.

 

**Example 1:**

**Input:** nums = [0,2,1]

**Output:** 2

**Explanation:**

- Rotate Left by one: `[2, 1, 0]`

- Reverse the array: `[0, 1, 2]`

The array becomes sorted in 2 operations, which is minimal

**Example 2:**

**Input:** nums = [1,0,2]

**Output:** 2

**Explanation:**

- Reverse the array: `[2, 0, 1]`

- Rotate Left by one: `[0, 1, 2]`

The array becomes sorted in 2 operations, which is minimal.

**Example 3:**

**Input:** nums = [2,0,1,3]

**Output:** -1

**Explanation:**

It is impossible to reach `[2, 0, 1, 3]`. Thus, the answer is -1.

 

**Constraints:**

- `1 <= n == nums.length <= 105`

- `0 <= nums[i] <= n - 1`

- `nums` is a permutation of integers from 0 to `n - 1`.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n, shift = len(nums), nums.index(0)
        ring = lambda k: nums[(shift + k) % n]  # the circle, read from 0
        if all(ring(k) == k for k in range(n)):  # counts up along the arrow
            return min(shift, n - shift + 2)  # walk ahead, or turn, walk back, turn back
        if all(ring(k) == -k % n for k in range(n)):  # counts up against the arrow
            return min(shift + 2, n - shift)  # walk ahead and turn, or turn and walk back
        return -1
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
