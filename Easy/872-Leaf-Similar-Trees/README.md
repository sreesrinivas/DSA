# [872. Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a **leaf value sequence***.*

For example, in the given tree above, the leaf value sequence is `(6, 7, 4, 9, 8)`.

Two binary trees are considered *leaf-similar* if their leaf value sequence is the same.

Return `true` if and only if the two given trees with head nodes `root1` and `root2` are leaf-similar.

 

**Example 1:**

```
Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
```

**Example 2:**

```
Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
```

 

**Constraints:**

- The number of nodes in each tree will be in the range `[1, 200]`.

- Both of the given trees will have values in the range `[0, 200]`.

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

 void leaf(TreeNode* root,vector<int>&leaves){

    if(root==NULL)return;   //iska matlab hai agar root null pr aa gyi to peeche chali jaye jaha se aayi hai

    if(root->left==NULL && root->right==NULL){ //iska matlab hai humari leaf node aa gyi

        leaves.push_back(root->val); //ab hum usse store kr rhe hai vector me and than return karke wapas bhej rhe hai 

        return;
    }

    leaf(root->left,leaves); //ab hum function ko firse call kr rhe hai but with the new root
    leaf(root->right,leaves); //ab hum function ko firse call kr rhe hai but with the new root
 }

 //iss question me mene ek leaf naam ka function bnaya hai jiske through me apne trees ki leaves ki value ek vector me store kr rhi hu and than unn vectors ko compare kr rhi hu

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int>leaves1,leaves2;  //do vectors banaye trees ki leaves ko store krne ke liye

        leaf(root1,leaves1); //first tree ke liye function ko call kiya
        leaf(root2,leaves2); //second tree ke liye function ko call kiya

        return leaves1==leaves2;  //compare kra dono vectors ko      
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
