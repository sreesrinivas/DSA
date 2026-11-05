# [878. Nth Magical Number](https://leetcode.com/problems/nth-magical-number/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A positive integer is *magical* if it is divisible by either `a` or `b`.

Given the three integers `n`, `a`, and `b`, return the `nth` magical number. Since the answer may be very large, **return it modulo **`109 + 7`.

 

**Example 1:**

```
Input: n = 1, a = 2, b = 3
Output: 2
```

**Example 2:**

```
Input: n = 4, a = 2, b = 3
Output: 6
```

 

**Constraints:**

- `1 <= n <= 109`

- `2 <= a, b <= 4 * 104`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int nthMagicalNumber(int n, int a, int b) {
        
        long A = a, B = b;
        long mod = (long)(Math.pow(10,9)+7);
        
        
        long left = Math.min(a,b), right = (long)n*Math.min(a,b);
        
		// Finding GCD
        while (B > 0) {
            long tmp = A;
            A = B;
            B = tmp % B;
        }
		
        long lcm = (a*b)/A;     //(n1*n2)/GCD
		
        while (left < right) {
            long m = left+(right-left)/2;
			
            if ((m / a) + (m / b) - (m / lcm) < n) left = m + 1;   
			
            else right = m;
        }
        return (int)(left % mod);
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
