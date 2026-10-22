# [508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given the `root` of a binary tree, return the most frequent **subtree sum**. If there is a tie, return all the values with the highest frequency in any order.

The **subtree sum** of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

 

**Example 1:**

```
Input: root = [5,2,-3]
Output: [2,-3,4]
```

**Example 2:**

```
Input: root = [5,2,-5]
Output: [2]
```

 

**Constraints:**

- The number of nodes in the tree is in the range `[1, 104]`.

- `-105 <= Node.val <= 105`

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;

    int fn(TreeNode* root, int& sum) {
        if (!root) {
            return 0;
        }
        sum = root->val + fn(root->left, sum) + fn(root->right, sum);
        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int sum = 0;
        fn(root, sum);

        int maxi = INT_MIN;
        for (auto& it : mp) {
            int freq = it.second;
            maxi = max(maxi, freq);
        }
        for (auto& it : mp) {
            int freq = it.second;
            if (freq == maxi) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
