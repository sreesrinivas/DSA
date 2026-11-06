# [897. Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given the `root` of a binary search tree, rearrange the tree in **in-order** so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

**Example 1:**

```
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
```

**Example 2:**

```
Input: root = [5,1,7]
Output: [1,null,5,null,7]
```

 

**Constraints:**

- The number of nodes in the given tree will be in the range `[1, 100]`.

- `0 <= Node.val <= 1000`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *iterator = nullptr;
        TreeNode *header = nullptr;
        vector<int> temp;
        Tree(root,temp);
        for(int i = 0; i < temp.size(); i++){
            if(i == 0){
                TreeNode *newnode = new TreeNode();
                newnode->left = nullptr;
                newnode->right = nullptr;
                newnode->val = temp[i];
                header = newnode;
                iterator = newnode;
            }
            else{
                TreeNode *newnode = new TreeNode();
                newnode->left = nullptr;
                newnode->right = nullptr;
                newnode->val = temp[i];
                iterator->right = newnode;
                iterator = iterator->right;
            }
        }
        return header;
    }
    void Tree(TreeNode *root, vector<int> &temp){
        if(root == nullptr) return;
        Tree(root->left,temp);
        temp.push_back(root->val);
        Tree(root->right,temp);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
