# [936. Stamping The Sequence](https://leetcode.com/problems/stamping-the-sequence/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given two strings `stamp` and `target`. Initially, there is a string `s` of length `target.length` with all `s[i] == '?'`.

In one turn, you can place `stamp` over `s` and replace every letter in the `s` with the corresponding letter from `stamp`.

- For example, if `stamp = "abc"` and `target = "abcba"`, then `s` is `"?????"` initially. In one turn you can:

	
place `stamp` at index `0` of `s` to obtain `"abc??"`,
place `stamp` at index `1` of `s` to obtain `"?abc?"`, or
place `stamp` at index `2` of `s` to obtain `"??abc"`.

	Note that `stamp` must be fully contained in the boundaries of `s` in order to stamp (i.e., you cannot place `stamp` at index `3` of `s`).

We want to convert `s` to `target` using **at most** `10 * target.length` turns.

Return *an array of the index of the left-most letter being stamped at each turn*. If we cannot obtain `target` from `s` within `10 * target.length` turns, return an empty array.

 

**Example 1:**

```
Input: stamp = "abc", target = "ababc"
Output: [0,2]
Explanation: Initially s = "?????".
- Place stamp at index 0 to get "abc??".
- Place stamp at index 2 to get "ababc".
[1,0,2] would also be accepted as an answer, as well as some other answers.
```

**Example 2:**

```
Input: stamp = "abca", target = "aabcaca"
Output: [3,0,1]
Explanation: Initially s = "???????".
- Place stamp at index 3 to get "???abca".
- Place stamp at index 0 to get "abcabca".
- Place stamp at index 1 to get "aabcaca".
```

 

**Constraints:**

- `1 <= stamp.length <= target.length <= 1000`

- `stamp` and `target` consist of lowercase English letters.

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
    def movesToStamp(self, stamp: str, target: str) -> List[int]:
        slen, tlen = len(stamp), len(target)
        res = []
        
        s_covers = set()   # create permutation of cover on characters in stamp
        for i in range(slen):
            for j in range(slen - i):
                s_covers.add('#' * i + stamp[i:slen-j] + '#' * j)
		# print(s_covers)
		
        done = '#' * tlen
		
        p = tlen - slen 
        while target != done:
            
            found = False
            for i in range(p, -1, -1):
                if target[i: i+slen] in s_covers:
                    target = target[:i] + '#' * slen + target[i+slen:]  # add the mask to the target
                    res.append(i)
                    found = True
            if not found:   # if we cannot find where to put the stamp, return empty array
                return []
        
        return res[::-1]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
