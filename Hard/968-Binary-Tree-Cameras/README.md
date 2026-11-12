# [968. Binary Tree Cameras](https://leetcode.com/problems/binary-tree-cameras/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given the `root` of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return *the minimum number of cameras needed to monitor all nodes of the tree*.

 

**Example 1:**

```
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
```

**Example 2:**

```
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.

- `Node.val == 0`

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
    // keep track of how many cams we placed globally
    int camera ;
    
    // returns 3 possible states for a node:
    // 0 -> im completely uncovered (need my parent to save me)
    // 1 -> i have a camera placed on me
    // 2 -> im already covered (one of my kids is watching me)
    int dfs(TreeNode* node){
        
        // base case: if it's a null node, just pretend it's covered.
        // we don't wanna put cams on literally nothing, and leaf nodes need to think their "kids" are fine.
        if( !node ) return 2 ;

        // check on the kids first (bottom-up approach)
        int l = dfs(node->left) ;
        int r = dfs(node->right) ;

        // scenario A: oh no, at least one kid is completely uncovered (0).
        // i literally HAVE to buy a camera right here to save them. no other choice.
        if( l == 0 || r == 0 ){
            camera++ ;
            return 1 ; // tell my parent i got a cam now
        }
        // scenario B: kids are fine, and at least one actually bought a cam (1).
        // sweet, that means im covered by their camera! i don't need to spend money.
        else if( l == 1 || r == 1 ) return 2 ;
        
        // scenario C: both kids are covered (2), but NEITHER has a camera on them.
        // so im left totally naked/vulnerable. ill just return 0 and pray my parent buys a cam for me lol.
        return 0 ;
    }
    
    int minCameraCover(TreeNode* root) {
        camera = 0 ;
        
        // run the dfs to cover the tree.
        // but wait... what if the root itself returns 0 (uncovered) at the very end?
        // it doesn't have a parent to bail it out! so we gotta forcefully buy one last cam just for the root.
        if( dfs(root) == 0 ) camera++ ;
        
        return camera ;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
