# [858. Mirror Reflection](https://leetcode.com/problems/mirror-reflection/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There is a special square room with mirrors on each of the four walls. Except for the southwest corner, there are receptors on each of the remaining corners, numbered `0`, `1`, and `2`.

The square room has walls of length `p` and a laser ray from the southwest corner first meets the east wall at a distance `q` from the `0th` receptor.

Given the two integers `p` and `q`, return *the number of the receptor that the ray meets first*.

The test cases are guaranteed so that the ray will meet a receptor eventually.

 

**Example 1:**

```
Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.
```

**Example 2:**

```
Input: p = 3, q = 1
Output: 1
```

 

**Constraints:**

- `1 <= q <= p <= 1000`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    
    int gcd(int a, int b) {
        while(b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
    
    int mirrorReflection(int p, int q) {
        int lcm = (p*q)/gcd(p, q); // calculating lcm using gcd
        int m = lcm/p;
        int n = lcm/q;
        if(m%2==0 && n%2==1) return 0;
        if(m%2==1 && n%2==1) return 1;
        if(m%2==1 && n%2==0) return 2;
        return -1;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
