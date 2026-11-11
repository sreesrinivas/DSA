# [927. Three Equal Parts](https://leetcode.com/problems/three-equal-parts/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an array `arr` which consists of only zeros and ones, divide the array into **three non-empty parts** such that all of these parts represent the same binary value.

If it is possible, return any `[i, j]` with `i + 1 < j`, such that:

- `arr[0], arr[1], ..., arr[i]` is the first part,

- `arr[i + 1], arr[i + 2], ..., arr[j - 1]` is the second part, and

- `arr[j], arr[j + 1], ..., arr[arr.length - 1]` is the third part.

- All three parts have equal binary values.

If it is not possible, return `[-1, -1]`.

Note that the entire part is used when considering what binary value it represents. For example, `[1,1,0]` represents `6` in decimal, not `3`. Also, leading zeros **are allowed**, so `[0,1,1]` and `[1,1]` represent the same value.

 

**Example 1:**

```
Input: arr = [1,0,1,0,1]
Output: [0,3]
```

**Example 2:**

```
Input: arr = [1,1,0,1,1]
Output: [-1,-1]
```

**Example 3:**

```
Input: arr = [1,1,0,0,1]
Output: [0,2]
```

 

**Constraints:**

- `3 <= arr.length <= 3 * 104`

- `arr[i]` is `0` or `1`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def threeEqualParts(self, A):
        n = len(A)
        indexes = [i for i in range(n) if A[i] == 1]
        m = len(indexes)
        
        if m == 0: return [0, 2]
        
        if m % 3 != 0: return [-1, -1]
        p1, p2 = indexes[0], indexes[m//3-1]
        p3, p4 = indexes[m//3], indexes[2*m//3-1]
        p5, p6 = indexes[2*m//3], indexes[-1]
        part1, part2, part3 = A[p1:p2+1], A[p3:p4+1], A[p5:p6+1]
        
        if part1 != part2 or part2 != part3: return [-1, -1]
        
        l1 = p3 - p2 - 1
        l2 = p5 - p4 - 1
        l3 = n - p6 - 1
        
        if l3 > l2 or l3 > l1: return [-1, -1]
        
        return [p2 + l3, p4 + l3 + 1]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
