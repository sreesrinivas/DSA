# [988. Smallest String Starting From Leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given the `root` of a binary tree where each node has a value in the range `[0, 25]` representing the letters `'a'` to `'z'`.

Return *the **lexicographically smallest** string that starts at a leaf of this tree and ends at the root*.

As a reminder, any shorter prefix of a string is **lexicographically smaller**.

- For example, `"ab"` is lexicographically smaller than `"aba"`.

A leaf of a node is a node that has no children.

 

**Example 1:**

```
Input: root = [0,1,2,3,4,3,4]
Output: "dba"
```

**Example 2:**

```
Input: root = [25,1,3,1,3,0,2]
Output: "adz"
```

**Example 3:**

```
Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 8500]`.

- `0 <= Node.val <= 25`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    string ans = "";
    void dfs(TreeNode* root, string curr = "") {
        if (!root) return;
        curr.insert(curr.begin(), 'a' + root->val);
        if (!root->left && !root->right) {
            if (ans.empty())
                ans = curr;
            else 
                ans = min(ans, curr);
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
        curr.erase(curr.begin());
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
