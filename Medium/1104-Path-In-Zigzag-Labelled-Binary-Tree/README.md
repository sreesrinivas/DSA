# [1104. Path In Zigzag Labelled Binary Tree](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

Given the `label` of a node in this tree, return the labels in the path from the root of the tree to the node with that `label`.

 

**Example 1:**

```
Input: label = 14
Output: [1,3,4,14]
```

**Example 2:**

```
Input: label = 26
Output: [1,2,6,10,26]
```

 

**Constraints:**

- `1 <= label <= 10^6`

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
    def pathInZigZagTree(self, label):
        res = [] # O(log n) space
        node_count = 1
        level = 1
        # Determine level of the label
        while label >= node_count*2: # O(log n) time
            node_count *= 2
            level += 1
        # Iterate from the target label to the root
        while label != 0: # O(log n) time
            res.append(label)
            level_max = 2**(level) - 1
            level_min = 2**(level-1)
            label = int((level_max + level_min - label)/2)
            level -= 1
        return res[::-1] # O(n) time
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
