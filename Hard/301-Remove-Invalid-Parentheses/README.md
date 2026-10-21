# [301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return *a list of **unique strings** that are valid with the minimum number of removals*. You may return the answer in **any order**.

 

**Example 1:**

```
Input: s = "()())()"
Output: ["(())()","()()()"]
```

**Example 2:**

```
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
```

**Example 3:**

```
Input: s = ")("
Output: [""]
```

 

**Constraints:**

- `1 <= s.length <= 25`

- `s` consists of lowercase English letters and parentheses `'('` and `')'`.

- There will be at most `20` parentheses in `s`.

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
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def isValid(s):
            i= 0
            ctr = 0
            while i<len(s):
                if s[i]== '(':
                    ctr += 1
                elif s[i] == ")":
                    if ctr == 0:
                        return False
                    ctr -= 1
                
                i +=1
            
            return ctr == 0
        
        level ={s}
        while True:
            valid = list(filter(isValid, level))
            if valid:
                return valid
            level = {s[:i] + s[i+1:] for i in range(len(s)) for s in level}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
