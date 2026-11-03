# [825. Friends Of Appropriate Ages](https://leetcode.com/problems/friends-of-appropriate-ages/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There are `n` persons on a social media website. You are given an integer array `ages` where `ages[i]` is the age of the `ith` person.

A Person `x` will not send a friend request to a person `y` (`x != y`) if any of the following conditions is true:

- `age[y] <= 0.5 * age[x] + 7`

- `age[y] > age[x]`

- `age[y] > 100 && age[x] < 100`

Otherwise, `x` will send a friend request to `y`.

Note that if `x` sends a request to `y`, `y` will not necessarily send a request to `x`. Also, a person will not send a friend request to themself.

Return *the total number of friend requests made*.

 

**Example 1:**

```
Input: ages = [16,16]
Output: 2
Explanation: 2 people friend request each other.
```

**Example 2:**

```
Input: ages = [16,17,18]
Output: 2
Explanation: Friend requests are made 17 -> 16, 18 -> 17.
```

**Example 3:**

```
Input: ages = [20,30,100,110,120]
Output: 3
Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.
```

 

**Constraints:**

- `n == ages.length`

- `1 <= n <= 2 * 104`

- `1 <= ages[i] <= 120`

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
    public int numFriendRequests(int[] ages) {
        int res = 0;
        Arrays.sort(ages);
        for (int i = 0; i < ages.length; ++i) {
            int age = ages[i];
            int lower = firstIdx(ages, age/2+7);
            int upper = firstIdx(ages, age);
            res += Math.max(upper-lower-1, 0);
        }
        return res;
    }
    
    private static int firstIdx(int[] ages, int target) {
        int beg = 0;
        int end = ages.length-1;
        while (beg <= end) {
            int mid = beg + (end-beg)/2;
            if (ages[mid] <= target) beg = mid + 1;
            else end = mid - 1;
        }
        return beg;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
