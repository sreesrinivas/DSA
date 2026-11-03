# [809. Expressive Words](https://leetcode.com/problems/expressive-words/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Sometimes people repeat letters to represent extra feeling. For example:

- `"hello" -> "heeellooo"`

- `"hi" -> "hiiii"`

In these strings like `"heeellooo"`, we have groups of adjacent letters that are all the same: `"h"`, `"eee"`, `"ll"`, `"ooo"`.

You are given a string `s` and an array of query strings `words`. A query word is **stretchy** if it can be made to be equal to `s` by any number of applications of the following extension operation: choose a group consisting of characters `c`, and add some number of characters `c` to the group so that the size of the group is **three or more**.

- For example, starting with `"hello"`, we could do an extension on the group `"o"` to get `"hellooo"`, but we cannot get `"helloo"` since the group `"oo"` has a size less than three. Also, we could do another extension like `"ll" -> "lllll"` to get `"helllllooo"`. If `s = "helllllooo"`, then the query word `"hello"` would be **stretchy** because of these two extension operations: `query = "hello" -> "hellooo" -> "helllllooo" = s`.

Return *the number of query strings that are **stretchy***.

 

**Example 1:**

```
Input: s = "heeellooo", words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not size 3 or more.
```

**Example 2:**

```
Input: s = "zzzzzyyyyy", words = ["zzyy","zy","zyy"]
Output: 3
```

 

**Constraints:**

- `1 <= s.length, words.length <= 100`

- `1 <= words[i].length <= 100`

- `s` and `words[i]` consist of lowercase letters.

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
class Solution:
    def expressiveWords(self, s: str, words: list[str]) -> int:
        def groups(w):  # "heeello" -> ('h', 'e', 'l', 'o'), (1, 3, 2, 1)
            return zip(*((ch, len(list(gr))) for ch, gr in groupby(w)))

        chars, counts = groups(s)

        def stretchy(word: str) -> bool:
            wchars, wcounts = groups(word)
            return wchars == chars and all(c == w or c >= max(3, w) for c, w in zip(counts, wcounts))

        return sum(map(stretchy, words))
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
