# [845. Longest Mountain in Array](https://leetcode.com/problems/longest-mountain-in-array/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You may recall that an array `arr` is a **mountain array** if and only if:

- `arr.length >= 3`

- There exists some index `i` (**0-indexed**) with `0 < i < arr.length - 1` such that:
	
`arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
`arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given an integer array `arr`, return *the length of the longest subarray, which is a mountain*. Return `0` if there is no mountain subarray.

 

**Example 1:**

```
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
```

**Example 2:**

```
Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
```

 

**Constraints:**

- `1 <= arr.length <= 104`

- `0 <= arr[i] <= 104`

 

**Follow up:**

- Can you solve it using only one pass?

- Can you solve it in `O(1)` space?

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
    public int longestMountain(int[] arr) {
        int n = arr.length;

        int[] left = new int[n];   // increasing run ending at i
        int[] right = new int[n];  // decreasing run starting at i

        for (int i = 0; i < n; i++) {
            left[i] = 1;
            right[i] = 1;
        }

        // climb from the left: extend the run if we're still going up
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) left[i] += left[i - 1];
        }

        // climb from the right: extend the run if we're still going down
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) right[i] += right[i + 1];
        }

        int maxi = 0;

        // a peak needs BOTH sides (> 1 each); peak counted once, hence -1
        for (int i = 0; i < n; i++) {
            if (left[i] > 1 && right[i] > 1)
                maxi = Math.max(maxi, left[i] + right[i] - 1);
        }

        return maxi;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
