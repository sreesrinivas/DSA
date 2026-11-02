# [788. Rotated Digits](https://leetcode.com/problems/rotated-digits/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

An integer `x` is a **good** if after rotating each digit individually by 180 degrees, we get a valid number that is different from `x`. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

- `0`, `1`, and `8` rotate to themselves,

- `2` and `5` rotate to each other (in this case they are rotated in a different direction, in other words, `2` or `5` gets mirrored),

- `6` and `9` rotate to each other, and

- the rest of the numbers do not rotate to any other number and become invalid.

Given an integer `n`, return *the number of **good** integers in the range *`[1, n]`.

 

**Example 1:**

```
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
```

**Example 2:**

```
Input: n = 1
Output: 0
```

**Example 3:**

```
Input: n = 2
Output: 1
```

 

**Constraints:**

- `1 <= n <= 104`

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
    def rotatedDigits(self, n: int) -> int:
        count = 0
        
        for i in range(1, n + 1):
            num = i
            isValid = True
            hasChange = False
            
            while num > 0:
                digit = num % 10
                
                if digit in [3, 4, 7]:
                    isValid = False
                    break
                
                if digit in [2, 5, 6, 9]:
                    hasChange = True
                
                num //= 10
            
            if isValid and hasChange:
                count += 1
        
        return count
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
