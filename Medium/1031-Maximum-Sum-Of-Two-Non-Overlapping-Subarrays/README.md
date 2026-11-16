# [1031. Maximum Sum of Two Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums` and two integers `firstLen` and `secondLen`, return *the maximum sum of elements in two non-overlapping **subarrays** with lengths *`firstLen`* and *`secondLen`.

The array with length `firstLen` could occur before or after the array with length `secondLen`, but they have to be non-overlapping.

A **subarray** is a **contiguous** part of an array.

 

**Example 1:**

```
Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
```

**Example 2:**

```
Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.
```

**Example 3:**

```
Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.
```

 

**Constraints:**

- `1 <= firstLen, secondLen <= 1000`

- `2 <= firstLen + secondLen <= 1000`

- `firstLen + secondLen <= nums.length <= 1000`

- `0 <= nums[i] <= 1000`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int n = nums.length;
        int[] pre = new int[n+1];
        pre[0] = 0;
        for (int i = 1; i < n+1; i++) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        int maxAns = Integer.MIN_VALUE;
        // firstLen first;
        int temp = -1;
        for (int i = n-secondLen; i >= firstLen; i--) {
            temp = Math.max(temp, pre[i + secondLen] - pre[i]);
            maxAns = Math.max(pre[i] - pre[i-firstLen] + temp, maxAns);
        }
        // secondLen first;
        temp = -1;
        for (int i = n-firstLen; i >= secondLen; i--) {
            temp = Math.max(temp, pre[i+firstLen] - pre[i]);
            maxAns = Math.max(pre[i] - pre[i-secondLen] + temp, maxAns);
        }
        return maxAns;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
