# [500. Keyboard Row](https://leetcode.com/problems/keyboard-row/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of strings `words`, return *the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below*.

**Note** that the strings are **case-insensitive**, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the **American keyboard**:

- the first row consists of the characters `"qwertyuiop"`,

- the second row consists of the characters `"asdfghjkl"`, and

- the third row consists of the characters `"zxcvbnm"`.

 

**Example 1:**

**Input:** words = ["Hello","Alaska","Dad","Peace"]

**Output:** ["Alaska","Dad"]

**Explanation:**

Both `"a"` and `"A"` are in the 2nd row of the American keyboard due to case insensitivity.

**Example 2:**

**Input:** words = ["omk"]

**Output:** []

**Example 3:**

**Input:** words = ["adsdf","sfd"]

**Output:** ["adsdf","sfd"]

 

**Constraints:**

- `1 <= words.length <= 20`

- `1 <= words[i].length <= 100`

- `words[i]` consists of English letters (both lowercase and uppercase).

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
def findWords(self, words):
    line1, line2, line3 = set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')
    ret = []
    for word in words:
      w = set(word.lower())
      if w <= line1 or w <= line2 or w <= line3:
        ret.append(word)
    return ret
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
