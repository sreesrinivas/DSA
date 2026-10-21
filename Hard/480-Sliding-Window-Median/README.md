# [480. Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

- For examples, if `arr = [2,3,4]`, the median is `3`.

- For examples, if `arr = [1,2,3,4]`, the median is `(2 + 3) / 2 = 2.5`.

You are given an integer array `nums` and an integer `k`. There is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the median array for each window in the original array*. Answers within `10-5` of the actual value will be accepted.

 

**Example 1:**

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
```

**Example 2:**

```
Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
```

 

**Constraints:**

- `1 <= k <= nums.length <= 105`

- `-231 <= nums[i] <= 231 - 1`

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
import java.util.*;

class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        List<Double> res = new ArrayList<>();

        // store first half [0 ... n/2]
        TreeSet<int[]> maxset = new TreeSet<>((a, b) -> {
            if (a[0] != b[0]) return b[0] - a[0];
            return b[1] - a[1];
        });

        // store second half [n/2 .... n]
        TreeSet<int[]> minset = new TreeSet<>((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        for (int i = 0; i < k; i++) {
            minset.add(new int[]{nums[i], i});
        }

        for (int i = 0; i < k / 2; i++) {
            int[] it = minset.first();
            maxset.add(it);
            minset.remove(it);
        }

        double median;
        if (k % 2 == 1)
            median = minset.first()[0];
        else
            median = (1.0 * maxset.first()[0] + 1.0 * minset.first()[0]) / 2.0;

        res.add(median);

        int r = k, l = 0;

        while (r < nums.length) {

            int[] add = new int[]{nums[r], r};
            int[] remove = new int[]{nums[l], l};
            int f = 1;

            if (maxset.contains(remove)) {
                maxset.remove(remove);
                f--;
            } else {
                minset.remove(remove);
            }

            if (f == 1) {
                maxset.add(add);
                int[] it = maxset.first();
                minset.add(it);
                maxset.remove(it);
            } else {
                minset.add(add);
                int[] it = minset.first();
                maxset.add(it);
                minset.remove(it);
            }

            if (k % 2 == 1)
                median = minset.first()[0];
            else
                median = (1.0 * maxset.first()[0] + 1.0 * minset.first()[0]) / 2.0;

            res.add(median);

            r++;
            l++;
        }

        double[] ans = new double[res.size()];
        for (int i = 0; i < res.size(); i++) ans[i] = res.get(i);
        
        return ans;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
