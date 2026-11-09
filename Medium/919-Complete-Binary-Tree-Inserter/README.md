# [919. Complete Binary Tree Inserter](https://leetcode.com/problems/complete-binary-tree-inserter/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: JavaScript](https://img.shields.io/badge/Language-JavaScript-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A **complete binary tree** is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the `CBTInserter` class:

- `CBTInserter(TreeNode root)` Initializes the data structure with the `root` of the complete binary tree.

- `int insert(int v)` Inserts a `TreeNode` into the tree with value `Node.val == val` so that the tree remains complete, and returns the value of the parent of the inserted `TreeNode`.

- `TreeNode get_root()` Returns the root node of the tree.

 

**Example 1:**

```
Input
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
Output
[null, 1, 2, [1, 2, 3, 4]]

Explanation
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // return 1
cBTInserter.insert(4);  // return 2
cBTInserter.get_root(); // return [1, 2, 3, 4]
```

 

**Constraints:**

- The number of nodes in the tree will be in the range `[1, 1000]`.

- `0 <= Node.val <= 5000`

- `root` is a complete binary tree.

- `0 <= val <= 5000`

- At most `104` calls will be made to `insert` and `get_root`.

---

## 💡 Solution Explanation

Two-pointer linear scan adjusting window boundaries based on constraints to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.js)**

```javascript
class CBTInserter{#t;#e=[];#h=0;constructor(t){this.#t=t;const e=[t];for(let t=0;t<e.length;t++){const h=e[t];h.left&&e.push(h.left),h.right&&e.push(h.right),h.left&&h.right||this.#e.push(h)}}insert(t){const e=this.#e[this.#h],h=new TreeNode(t);return e.left?(e.right=h,this.#h++):e.left=h,this.#e.push(h),e.val}get_root(){return this.#t}}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
