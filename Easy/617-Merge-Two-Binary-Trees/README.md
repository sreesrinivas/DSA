# [617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given two binary trees `root1` and `root2`.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return *the merged tree*.

**Note:** The merging process must start from the root nodes of both trees.

 

**Example 1:**

```
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
```

**Example 2:**

```
Input: root1 = [1], root2 = [1,2]
Output: [2,2]
```

 

**Constraints:**

- The number of nodes in both trees is in the range `[0, 2000]`.

- `-104 <= Node.val <= 104`

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
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
      if not t1 or not t2: return t1 or t2
      
      root = TreeNode(t1.val + t2.val)
      root.left = self.mergeTrees(t1.left, t2.left)
      root.right = self.mergeTrees(t1.right, t2.right)

      return root
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
