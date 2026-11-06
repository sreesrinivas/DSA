# [894. All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer `n`, return *a list of all possible **full binary trees** with* `n` *nodes*. Each node of each tree in the answer must have `Node.val == 0`.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in **any order**.

A **full binary tree** is a binary tree where each node has exactly `0` or `2` children.

 

**Example 1:**

```
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
```

**Example 2:**

```
Input: n = 3
Output: [[0,0,0]]
```

 

**Constraints:**

- `1 <= n <= 20`

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def solve(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        if n == 1:
            self.dp[1] = [TreeNode()]
            return self.dp[1]
        if len(self.dp[n]) > 0:
            return self.dp[n]
        ans = []
        for i in range(1, n, 2):
            Left = self.solve(i)
            Right = self.solve(n - 1 - i)
            for l in Left:
                for r in Right:
                    root = TreeNode()
                    root.left = l
                    root.right = r
                    ans.append(root)
        self.dp[n] = ans
        return ans

    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        self.dp = [[] for _ in range(n + 1)]
        return self.solve(n)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
