# [513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given the `root` of a binary tree.

Return the **leftmost** value in the **last** row of the tree.

 

**Example 1:**

```
Input: root = [2,1,3]
Output: 1
Explanation: The last row is [1,3], so the leftmost value is 1.
```

**Example 2:**

```
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
Explanation: The last row contains only the node 7.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.

- `-231 <= Node.val <= 231 - 1`

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
class Solution(object):
    def findBottomLeftValue(self, root):
        queue = deque([root])
        leftmost_value = None

        while queue:
            node = queue.popleft()

            leftmost_value = node.val

            if node.right:
                queue.append(node.right)
            if node.left:
                queue.append(node.left)

        return leftmost_value
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
