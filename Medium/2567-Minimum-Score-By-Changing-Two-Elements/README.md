# [2567. Minimum Score by Changing Two Elements](https://leetcode.com/problems/minimum-score-by-changing-two-elements/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums`.

- The **low** score of `nums` is the **minimum** absolute difference between any two integers.

- The **high** score of `nums` is the **maximum** absolute difference between any two integers.

- The **score** of `nums` is the sum of the **high** and **low** scores.

Return the **minimum score** after **changing two elements** of `nums`.

 

**Example 1:**

**Input:** nums = [1,4,7,8,5]

**Output:** 3

**Explanation:**

- Change `nums[0]` and `nums[1]` to be 6 so that `nums` becomes [6,6,7,8,5].

- The low score is the minimum absolute difference: |6 - 6| = 0.

- The high score is the maximum absolute difference: |8 - 5| = 3.

- The sum of high and low score is 3.

**Example 2:**

**Input:** nums = [1,4,3]

**Output:** 0

**Explanation:**

- Change `nums[1]` and `nums[2]` to 1 so that `nums` becomes [1,1,1].

- The sum of maximum absolute difference and minimum absolute difference is 0.

 

**Constraints:**

- `3 <= nums.length <= 105`

- `1 <= nums[i] <= 109`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int minimizeSum(int[] nums) {
        int[] small = new int[3], neg = new int[3];  // the 3 smallest values, and the 3 smallest negated ones: minus the 3 largest
        Arrays.fill(small, Integer.MAX_VALUE);
        Arrays.fill(neg, Integer.MAX_VALUE);
        for (int x : nums) {
            keep(small, x);
            keep(neg, -x);
        }
        return Math.min(-neg[0] - small[2], Math.min(-neg[1] - small[1], -neg[2] - small[0]));
    }

    private void keep(int[] three, int x) {  // three: the 3 smallest values so far, ascending
        if (x >= three[2])
            return;
        int i = 2;
        for (; i > 0 && three[i - 1] > x; i--)
            three[i] = three[i - 1];
        three[i] = x;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
