# [962. Maximum Width Ramp](https://leetcode.com/problems/maximum-width-ramp/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A **ramp** in an integer array `nums` is a pair `(i, j)` for which `i < j` and `nums[i] <= nums[j]`. The **width** of such a ramp is `j - i`.

Given an integer array `nums`, return *the maximum width of a **ramp** in *`nums`. If there is no **ramp** in `nums`, return `0`.

 

**Example 1:**

```
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
```

**Example 2:**

```
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
```

 

**Constraints:**

- `2 <= nums.length <= 5 * 104`

- `0 <= nums[i] <= 5 * 104`

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
    public int maxWidthRamp(int[] nums) {
       int[][] arr= new int[nums.length][2]; //Creating 2D array..
       for (int i = 0; i < nums.length; i++) {
            arr[i][0] = nums[i];  //stores values to the array
            arr[i][1] = i; //stores original indices
        }
        //sorting the 2D array using custom comparator
        Arrays.sort(arr,(a,b) -> Integer.compare(a[0], b[0])); 

        int minIndex = arr[0][1]; //// Ab tak ka minimum index track karo
        int maxWidth = 0;

        for (int i = 1; i < arr.length; i++) {
            // Calculate the width using the smallest index
            maxWidth = Math.max(maxWidth, arr[i][1] - minIndex);
            //update minimum index
            minIndex = Math.min(minIndex, arr[i][1]);
        }

        return maxWidth;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
