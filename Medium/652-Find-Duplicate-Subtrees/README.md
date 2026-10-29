# [652. Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given the `root` of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are **duplicate** if they have the **same structure** with the **same node values**.

 

**Example 1:**

```
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
```

**Example 2:**

```
Input: root = [2,1,1]
Output: [[1]]
```

**Example 3:**

```
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
```

 

**Constraints:**

- The number of the nodes in the tree will be in the range `[1, 5000]`

- `-200 <= Node.val <= 200`

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public String helper(
        TreeNode root,
        List<TreeNode> ans,
        Map<String, Integer> map
    ) {
        if (root == null) return "N";

        String s = root.val + "," +
                   helper(root.left, ans, map) + "," +
                   helper(root.right, ans, map);

        int count = map.getOrDefault(s, 0);

        if (count == 1) {
            ans.add(root);
        }

        map.put(s, count + 1);

        return s;
    }

    public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
        List<TreeNode> ans = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();

        helper(root, ans, map);

        return ans;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
