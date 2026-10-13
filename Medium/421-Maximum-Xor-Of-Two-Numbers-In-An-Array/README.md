# [421. Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums`, return *the maximum result of *`nums[i] XOR nums[j]`, where `0 <= i <= j < n`.

 

**Example 1:**

```
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
```

**Example 2:**

```
Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
```

 

**Constraints:**

- `1 <= nums.length <= 2 * 105`

- `0 <= nums[i] <= 231 - 1`

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
    public int findMaximumXOR(int[] nums) {
        int max = 0;
        for(int i = 0; i < nums.length - 1; i++){
            for(int j = i + 1; j < nums.length; j++){
                max = Math.max(max, nums[i] ^ nums[j]);
            }
        }
        return max;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
