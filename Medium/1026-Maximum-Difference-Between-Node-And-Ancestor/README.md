# [1026. Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: JavaScript](https://img.shields.io/badge/Language-JavaScript-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given the `root` of a binary tree, find the maximum value `v` for which there exist **different** nodes `a` and `b` where `v = |a.val - b.val|` and `a` is an ancestor of `b`.

A node `a` is an ancestor of `b` if either: any child of `a` is equal to `b` or any child of `a` is an ancestor of `b`.

 

**Example 1:**

```
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```

**Example 2:**

```
Input: root = [1,null,2,null,0,3]
Output: 3
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[2, 5000]`.

- `0 <= Node.val <= 105`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.js)**

```javascript
function LowestFromChild(lowest, highest) {
    this.lowest = lowest;
    this.highest = highest;
}

var maxAncestorDiff = function(root) {
    let maxDiff = 0;
    performInorder(root);
    return maxDiff;

    function performInorder(root) {
        if (!root) return null;

        const left = performInorder(root.left);
        const right = performInorder(root.right);

        if (!left && !right) {
            return new LowestFromChild(root.val, root.val);
        }

        const diffWithLeftChild = !left ?
            0 :
            Math.max(Math.abs(root.val - left.lowest), Math.abs(root.val - left.highest));

        const diffWithRightChild = !right ?
            0 :
            Math.max(Math.abs(root.val - right.lowest), Math.abs(root.val - right.highest));

        const currMaxDiff = Math.max(diffWithLeftChild, diffWithRightChild);
        maxDiff = Math.max(maxDiff, currMaxDiff);

        const leftLowest = left ? left.lowest : Number.MAX_SAFE_INTEGER;
        const leftHighest = left ? left.highest : Number.MIN_SAFE_INTEGER;
        const rightLowest = right ? right.lowest : Number.MAX_SAFE_INTEGER;
        const rightHighest = right ? right.highest : Number.MIN_SAFE_INTEGER;

        const lowestAtCurrNode = Math.min(root.val, Math.min(leftLowest, rightLowest));
        const highestAtCurrNode = Math.max(root.val, Math.max(leftHighest, rightHighest));

        return new LowestFromChild(lowestAtCurrNode, highestAtCurrNode);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
