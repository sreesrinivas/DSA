# [1054. Distant Barcodes](https://leetcode.com/problems/distant-barcodes/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

In a warehouse, there is a row of barcodes, where the `ith` barcode is `barcodes[i]`.

Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

 

**Example 1:**

```
Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
```

**Example 2:**

```
Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
```

 

**Constraints:**

- `1 <= barcodes.length <= 10000`

- `1 <= barcodes[i] <= 10000`

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int code : barcodes) {
            freq.put(code, freq.getOrDefault(code, 0) + 1);
        }

        // Max-heap based on frequency
        PriorityQueue<int[]> pq = new PriorityQueue<>(
            (a, b) -> b[0] - a[0]
        );

        for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
            pq.add(new int[]{entry.getValue(), entry.getKey()});
        }

        int n = barcodes.length;
        int[] res = new int[n];
        int i = 0;

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int count = curr[0], val = curr[1];
            while (count-- > 0) {
                if (i >= n) i = 1;
                res[i] = val;
                i += 2;
            }
        }

        return res;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
