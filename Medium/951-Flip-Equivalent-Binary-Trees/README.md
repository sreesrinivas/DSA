# [951. Flip Equivalent Binary Trees](https://leetcode.com/problems/flip-equivalent-binary-trees/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

For a binary tree **T**, we can define a **flip operation** as follows: choose any node, and swap the left and right child subtrees.

A binary tree **X** is *flip equivalent* to a binary tree **Y** if and only if we can make **X** equal to **Y** after some number of flip operations.

Given the roots of two binary trees `root1` and `root2`, return `true` if the two trees are flip equivalent or `false` otherwise.

 

**Example 1:**

```
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
```

**Example 2:**

```
Input: root1 = [], root2 = []
Output: true
```

**Example 3:**

```
Input: root1 = [], root2 = [1]
Output: false
```

 

**Constraints:**

- The number of nodes in each tree is in the range `[0, 100]`.

- Each tree will have **unique node values** in the range `[0, 99]`.

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
    bool isFlippedOrNot(TreeNode* L, TreeNode* R){
        // if both of them are not present
         if (!L && !R)
            return true;

        // if only one of them is absent
        if (!L || !R)
            return false;

        // check the value if they are equal
        return L->val == R->val;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // if both of them are absent
        if(!root1 && !root2) return true;
        // if only one of them are absent
        if(!root1 || !root2) return false;
        // stack represents the node that we have discovered but yet to process
        stack<pair<TreeNode*,TreeNode*>>st;
        st.push({root1,root2});
        // until all the nodes gets processed
        while(!st.empty()){
        auto [L,R] = st.top();
        st.pop();  

        // if both nodes doesn't exist
        if(!L && !R) continue;
        // if only one of them exists
        if(!L || !R) return false;
        // if they both exists but don't have the same value
        if(L->val != R->val) return false;
            /*
                At this point we have two possible alignments:
                1. No flip:
                       L->left  <-> R->left
                       L->right <-> R->right
                2. Flip:
                       L->left  <-> R->right
                       L->right <-> R->left
            */
            bool noFlip =
                isFlippedOrNot(L->left, R->left) &&
                isFlippedOrNot(L->right, R->right);
            bool flip =
                isFlippedOrNot(L->left, R->right) &&
                isFlippedOrNot(L->right, R->left);

            if (!noFlip && !flip)
                return false;

            /*
                If both are possible, we cannot simply choose one
                because the deeper structure may invalidate that choice.
                So we preserve both possibilities.
            */
            if (noFlip) {
                st.push({L->left, R->left});
                st.push({L->right, R->right});
            }

            if (flip) {
                st.push({L->left, R->right});
                st.push({L->right, R->left});
            }
        }
    return true;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
