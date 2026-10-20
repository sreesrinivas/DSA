# [449. Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a **binary search tree**. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

**The encoded string should be as compact as possible.**

 

**Example 1:**

```
Input: root = [2,1,3]
Output: [2,1,3]
```

**Example 2:**

```
Input: root = []
Output: []
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.

- `0 <= Node.val <= 104`

- The input tree is **guaranteed** to be a binary search tree.

---

## 💡 Solution Explanation

Two-pointer linear scan adjusting window boundaries based on constraints to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Codec {
    void mySerial(TreeNode* root, string &s) {
        if (root == nullptr) return ;
        s += to_string(root->val) + " ";
        mySerial(root->left, s);
        mySerial(root->right, s);
    }
    TreeNode* myDeserial(queue<int> &q, int lo, int hi) {
        if (q.empty()) return nullptr;
        int val = q.front();
        if (val < lo || val > hi) return nullptr;
        TreeNode *root = new TreeNode(val);
        q.pop();
        root->left  = myDeserial(q, lo, val);
        root->right = myDeserial(q, val, hi);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        mySerial(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        queue<int> q;
        string s;
        while (iss >> s) q.push(stoi(s));
        return myDeserial(q, INT_MIN, INT_MAX);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
