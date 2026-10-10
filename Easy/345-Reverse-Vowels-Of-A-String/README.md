# [345. Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s`, reverse only all the vowels in the string and return it.

The vowels are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`, and they can appear in both lower and upper cases, more than once.

 

**Example 1:**

**Input:** s = "IceCreAm"

**Output:** "AceCreIm"

**Explanation:**

The vowels in `s` are `['I', 'e', 'e', 'A']`. On reversing the vowels, s becomes `"AceCreIm"`.

**Example 2:**

**Input:** s = "leetcode"

**Output:** "leotcede"

 

**Constraints:**

- `1 <= s.length <= 3 * 105`

- `s` consist of **printable ASCII** characters.

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
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        i=0
        j=len(s)-1
        vowels={'a','e','i','o','u','A','E','I','O','U'}
        while i<=j:
            if  s[i] in vowels and s[j] in vowels:
                s[i], s[j] = s[j], s[i]
                i=i+1
                j=j-1
            elif s[i] in vowels:
                j=j-1
            elif s[j] in vowels:
                i=i+1
            else:
                i=i+1
                j=j-1
        return "".join(s)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
