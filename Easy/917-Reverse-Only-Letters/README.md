# [917. Reverse Only Letters](https://leetcode.com/problems/reverse-only-letters/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s`, reverse the string according to the following rules:

- All the characters that are not English letters remain in the same position.

- All the English letters (lowercase or uppercase) should be reversed.

Return `s`* after reversing it*.

 

**Example 1:**

```
Input: s = "ab-cd"
Output: "dc-ba"
```

**Example 2:**

```
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
```

**Example 3:**

```
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
```

 

**Constraints:**

- `1 <= s.length <= 100`

- `s` consists of characters with ASCII values in the range `[33, 122]`.

- `s` does not contain `'\"'` or `'\\'`.

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
    def reverseOnlyLetters(self, s: str) -> str:
        letters = []

        # Store all letters
        for c in s:
            if c.isalpha():
                letters.append(c)

        # Reverse the letters
        letters.reverse()

        # Put reversed letters back
        result = list(s)
        index = 0

        for i in range(len(result)):
            if result[i].isalpha():
                result[i] = letters[index]
                index += 1

        return ''.join(result)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
