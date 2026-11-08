# [888. Fair Candy Swap](https://leetcode.com/problems/fair-candy-swap/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Alice and Bob have a different total number of candies. You are given two integer arrays `aliceSizes` and `bobSizes` where `aliceSizes[i]` is the number of candies of the `ith` box of candy that Alice has and `bobSizes[j]` is the number of candies of the `jth` box of candy that Bob has.

Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.

Return a*n integer array *`answer`* where *`answer[0]`* is the number of candies in the box that Alice must exchange, and *`answer[1]`* is the number of candies in the box that Bob must exchange*. If there are multiple answers, you may **return any** one of them. It is guaranteed that at least one answer exists.

 

**Example 1:**

```
Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]
```

**Example 2:**

```
Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]
```

**Example 3:**

```
Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]
```

 

**Constraints:**

- `1 <= aliceSizes.length, bobSizes.length <= 104`

- `1 <= aliceSizes[i], bobSizes[j] <= 105`

- Alice and Bob have a different total number of candies.

- There will be at least one valid answer for the given input.

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
    public int[] fairCandySwap(int[] a, int[] b) {
        int asum = 0 , bsum = 0;

        for(int num : a){
            asum += num;
        }

        HashSet<Integer> bobset = new HashSet<>();
        for(int num : b){
            bsum += num;
            bobset.add(num);
        }

        int diff = (bsum - asum)/2;

        for(int x : a){
            int target = x + diff;
            if(bobset.contains(target)){
                return new int[]{x, target};
            }
        }
        return new int[0];
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
