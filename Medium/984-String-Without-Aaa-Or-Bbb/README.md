# [984. String Without AAA or BBB](https://leetcode.com/problems/string-without-aaa-or-bbb/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given two integers `a` and `b`, return **any** string `s` such that:

- `s` has length `a + b` and contains exactly `a` `'a'` letters, and exactly `b` `'b'` letters,

- The substring `'aaa'` does not occur in `s`, and

- The substring `'bbb'` does not occur in `s`.

 

**Example 1:**

```
Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
```

**Example 2:**

```
Input: a = 4, b = 1
Output: "aabaa"
```

 

**Constraints:**

- `0 <= a, b <= 100`

- It is guaranteed such an `s` exists for the given `a` and `b`.

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
    def strWithout3a3b(self, A: int, B: int) -> str:
        if A > B:
            numberToLayDown = A
            numberToTopUp = B
            charToLayDown = "a"
            charToTopUp = "b"
        else:
            numberToLayDown = B
            numberToTopUp = A
            charToLayDown = "b"
            charToTopUp = "a"

            
        repetition = int(numberToLayDown / 2)
        remainder = numberToLayDown % 2
        
        stk = []
        for i in range(repetition):
            stk.append(charToLayDown + charToLayDown)
        if remainder:
            stk.append(charToLayDown)
        
        stkSize = len(stk)
        stkIdx = 0
        while numberToTopUp > 0:
            stk[stkIdx] += charToTopUp
            stkIdx = (stkIdx + 1) % stkSize
            numberToTopUp -= 1
            
        return "".join(stk)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
