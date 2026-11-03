# [828. Count Unique Characters of All Substrings of a Given String](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Let's define a function `countUniqueChars(s)` that returns the number of unique characters in `s`.

- For example, calling `countUniqueChars(s)` if `s = "LEETCODE"` then `"L"`, `"T"`, `"C"`, `"O"`, `"D"` are the unique characters since they appear only once in `s`, therefore `countUniqueChars(s) = 5`.

Given a string `s`, return the sum of `countUniqueChars(t)` where `t` is a substring of `s`. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

 

**Example 1:**

```
Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
```

**Example 2:**

```
Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
```

**Example 3:**

```
Input: s = "LEETCODE"
Output: 92
```

 

**Constraints:**

- `1 <= s.length <= 105`

- `s` consists of uppercase English letters only.

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
class Solution(object):
    def uniqueLetterString(self, s):
        if s is None:
            raise RuntimeError("Bad input; s cannot be None")
        lastSeen = {}
        retval = 0
        lastStepCount = 0
        for i in range(len(s)):
            lastTwoSeenIndices = lastSeen.get(s[i], None)
            if not lastTwoSeenIndices:
                currentStepCount = lastStepCount + i + 1
                lastSeen[s[i]] = (-1, i)
            else:
                secondLastSeenIndex, lastSeenIndex = lastTwoSeenIndices
                numOfSuffixesWithoutCurrChar = i - 1 - lastSeenIndex
                numOfSuffixesWithJustOneOccurrenceOfCurrChar = \
                    lastSeenIndex - secondLastSeenIndex
                currentStepCount = \
                    lastStepCount + \
                    1 + \
                    numOfSuffixesWithoutCurrChar - \
                    numOfSuffixesWithJustOneOccurrenceOfCurrChar
                lastSeen[s[i]] = (lastSeenIndex, i)
            
            retval += currentStepCount
            lastStepCount = currentStepCount

        return retval
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
