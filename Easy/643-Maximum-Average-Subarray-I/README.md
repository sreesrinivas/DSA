# [643. Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose **length is equal to** `k` that has the maximum average value and return *this value*. Any answer with a calculation error less than `10-5` will be accepted.

 

**Example 1:**

```
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
```

**Example 2:**

```
Input: nums = [5], k = 1
Output: 5.00000
```

 

**Constraints:**

- `n == nums.length`

- `1 <= k <= n <= 105`

- `-104 <= nums[i] <= 104`

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
    public double findMaxAverage(int[] nums, int k) {
        int i = 0;
        int j = 0;
        double sum = 0;
        double maxAvg = Double.NEGATIVE_INFINITY;

        while (j < nums.length) {
            sum = sum + nums[j];

            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                maxAvg = Math.max(maxAvg, sum / k);
                sum = sum - nums[i];

                i++;
                j++;
            }

        }
        return maxAvg;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
