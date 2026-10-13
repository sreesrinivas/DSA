# [420. Strong Password Checker](https://leetcode.com/problems/strong-password-checker/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A password is considered strong if the below conditions are all met:

- It has at least `6` characters and at most `20` characters.

- It contains at least **one lowercase** letter, at least **one uppercase** letter, and at least **one digit**.

- It does not contain three repeating characters in a row (i.e., `"Baaabb0"` is weak, but `"Baaba0"` is strong).

Given a string `password`, return *the minimum number of steps required to make `password` strong. if `password` is already strong, return `0`.*

In one step, you can:

- Insert one character to `password`,

- Delete one character from `password`, or

- Replace one character of `password` with another character.

 

**Example 1:**

```
Input: password = "a"
Output: 5
```

**Example 2:**

```
Input: password = "aA1"
Output: 3
```

**Example 3:**

```
Input: password = "1337C0d3"
Output: 0
```

 

**Constraints:**

- `1 <= password.length <= 50`

- `password` consists of letters, digits, dot `'.'` or exclamation mark `'!'`.

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
class Solution(object):
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        missing_type = 3
        if any('a' <= c <= 'z' for c in s): missing_type -= 1
        if any('A' <= c <= 'Z' for c in s): missing_type -= 1
        if any(c.isdigit() for c in s): missing_type -= 1

        change = 0
        one = two = 0
        p = 2
        while p < len(s):
            if s[p] == s[p-1] == s[p-2]:
                length = 2
                while p < len(s) and s[p] == s[p-1]:
                    length += 1
                    p += 1
                    
                change += length / 3
                if length % 3 == 0: one += 1
                elif length % 3 == 1: two += 1
            else:
                p += 1
        
        if len(s) < 6:
            return max(missing_type, 6 - len(s))
        elif len(s) <= 20:
            return max(missing_type, change)
        else:
            delete = len(s) - 20
            
            change -= min(delete, one)
            change -= min(max(delete - one, 0), two * 2) / 2
            change -= max(delete - one - 2 * two, 0) / 3
                
            return delete + max(missing_type, change)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
