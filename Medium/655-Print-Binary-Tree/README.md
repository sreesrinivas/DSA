# [655. Print Binary Tree](https://leetcode.com/problems/print-binary-tree/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given the `root` of a binary tree, construct a **0-indexed** `m x n` string matrix `res` that represents a **formatted layout** of the tree. The formatted layout matrix should be constructed using the following rules:

- The **height** of the tree is `height` and the number of rows `m` should be equal to `height + 1`.

- The number of columns `n` should be equal to `2height+1 - 1`.

- Place the **root node** in the **middle** of the **top row** (more formally, at location `res[0][(n-1)/2]`).

- For each node that has been placed in the matrix at position `res[r][c]`, place its **left child** at `res[r+1][c-2height-r-1]` and its **right child** at `res[r+1][c+2height-r-1]`.

- Continue this process until all the nodes in the tree have been placed.

- Any empty cells should contain the empty string `""`.

Return *the constructed matrix *`res`.

 

**Example 1:**

```
Input: root = [1,2]
Output: 
[["","1",""],
 ["2","",""]]
```

**Example 2:**

```
Input: root = [1,2,3,null,4]
Output: 
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 210]`.

- `-99 <= Node.val <= 99`

- The depth of the tree will be in the range `[1, 10]`.

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeight(TreeNode* root){
        if(!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void preorder(TreeNode* root, int r, int c, int height, vector<vector<string>>& ans){
        if(!root) return;

        if(root->left){
            int row = r+1 , col = c - pow(2, height-r-1);
            ans[row][col] = to_string(root->left->val);
            preorder(root->left,row, col, height, ans);
        }

        if(root->right){
            int row = r+1 , col = c + pow(2, height-r-1);
            ans[row][col] = to_string(root->right->val);
            preorder(root->right,row, col, height, ans);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root), n = pow(2,height)-1;
        vector<vector<string>> ans(height, vector<string>(n, ""));
        ans[0][(n-1)/2] += to_string(root->val);
        preorder(root,0,(n-1)/2, height-1, ans);

        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
