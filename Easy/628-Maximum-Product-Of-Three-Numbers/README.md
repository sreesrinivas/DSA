# [628. Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums`.

Find three numbers whose product is **maximum** and return the **maximum** product.

 

**Example 1:**

**Input:** nums = [1,2,-3]

**Output:** -6

**Explanation:**

The only three numbers are 1, 2, and -3, so the maximum product is `1 * 2 * -3 = -6`.

**Example 2:**

**Input:** nums = [1,2,3,4]

**Output:** 24

**Explanation:**

The largest product comes from the three greatest numbers: `2 * 3 * 4 = 24`.

**Example 3:**

**Input:** nums = [-1,-2,-3]

**Output:** -6

**Explanation:**

The only three numbers are -1, -2, and -3, so the maximum product is `(-1) * (-2) * (-3) = -6`.

 

**Constraints:**

- `3 <= nums.length <= 104`

- `-1000 <= nums[i] <= 1000`

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int maximumProduct(int[] nums){
        int n = nums.length;

        Arrays.sort(nums);

        int poss1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int poss2 = nums[0] * nums[1] * nums[n - 1];

        return Math.max(poss1, poss2);
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
