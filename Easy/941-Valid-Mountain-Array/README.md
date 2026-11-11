# [941. Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of integers `arr`, return *`true` if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- `arr.length >= 3`

- There exists some `i` with `0 < i < arr.length - 1` such that:
	
`arr[0] < arr[1] < ... < arr[i - 1] < arr[i] `
`arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

 

**Example 1:**

```
Input: arr = [2,1]
Output: false
```

**Example 2:**

```
Input: arr = [3,5,5]
Output: false
```

**Example 3:**

```
Input: arr = [0,3,2,1]
Output: true
```

 

**Constraints:**

- `1 <= arr.length <= 104`

- `0 <= arr[i] <= 104`

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
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3: return False;
        l = 0;
        r = len(arr) - 1
        while l + 1 < len(arr) - 1 and arr[l] < arr[l + 1]: 
            l += 1
        while r - 1 > 0 and arr[r] < arr[r - 1]: 
            r -= 1
        return l == r
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
