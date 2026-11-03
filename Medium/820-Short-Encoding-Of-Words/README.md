# [820. Short Encoding of Words](https://leetcode.com/problems/short-encoding-of-words/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A **valid encoding** of an array of `words` is any reference string `s` and array of indices `indices` such that:

- `words.length == indices.length`

- The reference string `s` ends with the `'#'` character.

- For each index `indices[i]`, the **substring** of `s` starting from `indices[i]` and up to (but not including) the next `'#'` character is equal to `words[i]`.

Given an array of `words`, return *the **length of the shortest reference string** *`s`* possible of any **valid encoding** of *`words`*.*

 

**Example 1:**

```
Input: words = ["time", "me", "bell"]
Output: 10
Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
```

**Example 2:**

```
Input: words = ["t"]
Output: 2
Explanation: A valid encoding would be s = "t#" and indices = [0].
```

 

**Constraints:**

- `1 <= words.length <= 2000`

- `1 <= words[i].length <= 7`

- `words[i]` consists of only lowercase letters.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        s_length = 0
        
        # use set to remove duplicated words
        words_set = set(words)
        
        # sort by length in descending order
        sorted_words = sorted(words, key=len, reverse=True)
        
        # check from the longest word
        for word in sorted_words:
            print(word)
            if word in words_set:
                # add length of word + '#' char
                s_length += len(word) + 1
        
            # for all suffix words of current word
            for i in range(0, len(word) + 1):
                # remove suffix word since it does not affect to the final length
                if word[-i:] in words_set:
                    words_set.remove(word[-i:])
        
        return s_length
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
