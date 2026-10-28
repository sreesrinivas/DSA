# [662. Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given the `root` of a binary tree, return *the **maximum width** of the given tree*.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is **guaranteed** that the answer will in the range of a **32-bit** signed integer.

 

**Example 1:**

```
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
```

**Example 2:**

```
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
```

**Example 3:**

```
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 3000]`.

- `-100 <= Node.val <= 100`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {  
    public record Pair(TreeNode node, int val) {
    }
    public int widthOfBinaryTree(TreeNode root) {
        int maxi = 0;
        if (root == null)
            return maxi;
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(root, 1));
        while (!q.isEmpty()) {
            int n = q.size();
            int minIdx = 0;
            int maxIdx = 0;
            
            for (int i = 0; i < n; i++) {
                Pair p = q.poll();
                TreeNode node = p.node;
                int val = p.val;

                if(i == 0) minIdx = val;  // Left Most Value in a level
                if(i == n-1) maxIdx = val;  // Right Most Value in a level

                if (node.left != null) 
                    q.offer(new Pair(node.left, (val - minIdx) * 2 + 1));
                if (node.right != null)
                    q.offer(new Pair(node.right, (val - minIdx) * 2 + 2));
            }

            maxi = Math.max(maxi, maxIdx - minIdx + 1);
        }
        return maxi;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
