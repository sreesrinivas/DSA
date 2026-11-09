# [906. Super Palindromes](https://leetcode.com/problems/super-palindromes/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Let's say a positive integer is a **super-palindrome** if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers `left` and `right` represented as strings, return *the number of **super-palindromes** integers in the inclusive range* `[left, right]`.

 

**Example 1:**

```
Input: left = "4", right = "1000"
Output: 4
Explanation: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
```

**Example 2:**

```
Input: left = "1", right = "2"
Output: 1
```

 

**Constraints:**

- `1 <= left.length, right.length <= 18`

- `left` and `right` consist of only digits.

- `left` and `right` cannot have leading zeros.

- `left` and `right` represent integers in the range `[1, 1018 - 1]`.

- `left` is less than or equal to `right`.

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
    def superpalindromesInRange(self, left: str, right: str) -> int:
        ans = 1 if 9 >= int(left) and 9 <= int(right) else 0
        
        def isPal(s: str) -> bool:
            return s == s[::-1]
        
        for dig in range(1, 10):
            isOdd = dig % 2 and dig != 1
            innerLen = (dig >> 1) - 1
            innerLim = max(1, 2 ** innerLen)
            midPos = dig >> 1
            midLim = 3 if isOdd else 1
            for edge in range (1, 3):
                pal = [0] * dig
                pal[0], pal[-1] = edge, edge
                if edge == 2: innerLim, midLim = 1, min(midLim, 2)
                for inner in range(innerLim):
                    if inner > 0:
                        innerStr = list(bin(inner)[2:].zfill(innerLen))
                        pal[1:1+innerLen] = innerStr
                        pal[-innerLen-1:-1] = reversed(innerStr)
                    for mid in range(midLim):
                        if isOdd: pal[midPos] = mid
                        palin = int("".join([str(n) for n in pal]))
                        square = palin * palin
                        if square > int(right): return ans
                        if square >= int(left) and isPal(str(square)): ans += 1
        return ans
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
