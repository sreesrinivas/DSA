# [768. Max Chunks To Make Sorted II](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `arr`.

We split `arr` into some number of **chunks** (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return *the largest number of chunks we can make to sort the array*.

 

**Example 1:**

```
Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
```

**Example 2:**

```
Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
```

 

**Constraints:**

- `1 <= arr.length <= 2000`

- `0 <= arr[i] <= 108`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();

        // rMin[i] = minimum element from i ... n-1
        vector<int> rMin(n);
        rMin[n - 1] = arr[n - 1];

        for(int i = n - 2; i >= 0; i--)
            rMin[i] = min(rMin[i + 1], arr[i]);

        int leftMax = arr[0];
        int chunks = 0;

        // Try every possible split.
        for(int i = 0; i < n - 1; i++)
        {
            leftMax = max(leftMax, arr[i]);

            // Every element on the left is <= every element on the right.
            if(leftMax <= rMin[i + 1])
                chunks++;
        }

        // Last chunk.
        return chunks + 1;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
