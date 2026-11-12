# [961. N-Repeated Element in Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums` with the following properties:

- `nums.length == 2 * n`.

- `nums` contains `n + 1` **unique** values, `n` of which occur **exactly once** in the array.

- Exactly one element of `nums` is repeated `n` times.

Return *the element that is repeated *`n`* times*.

 

**Example 1:**

```
Input: nums = [1,2,3,3]
Output: 3
```

**Example 2:**

```
Input: nums = [2,1,2,5,3,2]
Output: 2
```

**Example 3:**

```
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5
```

 

**Constraints:**

- `2 <= n <= 5000`

- `nums.length == 2 * n`

- `0 <= nums[i] <= 104`

- `nums` contains `n + 1` **unique** elements and one of them is repeated exactly `n` times.

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        
        mp = {}
        for i in nums:
            if i in mp:
                return i
        
            mp[i] = 1
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
