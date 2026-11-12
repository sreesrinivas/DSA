# [965. Univalued Binary Tree](https://leetcode.com/problems/univalued-binary-tree/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A binary tree is **uni-valued** if every node in the tree has the same value.

Given the `root` of a binary tree, return `true`* if the given tree is **uni-valued**, or *`false`* otherwise.*

 

**Example 1:**

```
Input: root = [1,1,1,1,1,null,1]
Output: true
```

**Example 2:**

```
Input: root = [2,2,2,5,2]
Output: false
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.

- `0 <= Node.val < 100`

---

## 💡 Solution Explanation

Two-pointer linear scan adjusting window boundaries based on constraints to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: TreeNode | None) -> bool:
        if root is None:
            return True
        
        if root.left and root.left.val != root.val:
            return False

        if root.right and root.right.val != root.val:
            return False

        return (
            self.isUnivalTree(root.left)
            and 
            self.isUnivalTree(root.right)
        )
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
