# [839. Similar String Groups](https://leetcode.com/problems/similar-string-groups/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Two strings, `X` and `Y`, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string `X`.

For example, `"tars"` and `"rats"` are similar (swapping at positions `0` and `2`), and `"rats"` and `"arts"` are similar, but `"star"` is not similar to `"tars"`, `"rats"`, or `"arts"`.

Together, these form two connected groups by similarity: `{"tars", "rats", "arts"}` and `{"star"}`.  Notice that `"tars"` and `"arts"` are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list `strs` of strings where every string in `strs` is an anagram of every other string in `strs`. How many groups are there?

 

**Example 1:**

```
Input: strs = ["tars","rats","arts","star"]
Output: 2
```

**Example 2:**

```
Input: strs = ["omv","ovm"]
Output: 1
```

 

**Constraints:**

- `1 <= strs.length <= 300`

- `1 <= strs[i].length <= 300`

- `strs[i]` consists of lowercase letters only.

- All words in `strs` have the same length and are anagrams of each other.

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
    def numSimilarGroups(self, strs: List[str]) -> int:
        groups = 0
        n = len(strs)
        vis = [False] * n
        for i in range(n):
            if vis[i]: continue
            groups += 1
            self.dfs(i, strs, vis)
        return groups

    def dfs(self, i: int, strs: List[str], vis: List[bool]) -> None:
        vis[i] = True
        for j in range(len(strs)):
            if vis[j]: continue
            if self.is_similar(strs[i], strs[j]):
                self.dfs(j, strs, vis)

    def is_similar(self, a: str, b: str) -> bool:
        count = 0
        for i in range(len(a)):
            if a[i] != b[i]: count += 1
        return count == 2 or count == 0
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
