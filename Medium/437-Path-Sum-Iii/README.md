# [437. Path Sum III](https://leetcode.com/problems/path-sum-iii/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given the `root` of a binary tree and an integer `targetSum`, return *the number of paths where the sum of the values along the path equals* `targetSum`.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

**Example 1:**

```
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
```

**Example 2:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[0, 1000]`.

- `-109 <= Node.val <= 109`

- `-1000 <= targetSum <= 1000`

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
class Solution {
public:
    long long cnt = 0;

    // Counts all valid downward paths
    // starting exactly from 'root'.
    void dfs(TreeNode* root, long long sum, long long targetSum)
    {
        if(root == nullptr)
            return;

        sum += root->val;

        if(sum == targetSum)
            cnt++;

        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {

        if(root == nullptr)
            return 0;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            // Every node becomes a starting point.
            dfs(node, 0, targetSum);

            if(node->right)
                st.push(node->right);

            if(node->left)
                st.push(node->left);
        }

        return cnt;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
