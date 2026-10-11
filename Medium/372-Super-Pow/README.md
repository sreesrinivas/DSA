# [372. Super Pow](https://leetcode.com/problems/super-pow/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Your task is to calculate `ab` mod `1337` where `a` is a positive integer and `b` is an extremely large positive integer given in the form of an array.

 

**Example 1:**

**Input:** a = 2, b = [3]

**Output:** 8

**Explanation:**

The array `b = [3]` represents the exponent 3. Therefore, `a3 = 23 = 8`, so the result is 8.

**Example 2:**

**Input:** a = 2, b = [1,0]

**Output:** 1024

**Explanation:**

The array `b = [1, 0]` represents the exponent 10. Therefore, `a10 = 210 = 1024`, so the result is 1024.

**Example 3:**

**Input:** a = 1, b = [4,3,3,8,5,2]

**Output:** 1

**Explanation:**

The array `b = [4, 3, 3, 8, 5, 2]` represents a positive exponent. Since `a = 1`, any positive power of 1 is 1. Therefore, the result is 1.

 

**Constraints:**

- `1 <= a <= 231 - 1`

- `1 <= b.length <= 2000`

- `0 <= b[i] <= 9`

- `b` does not contain leading zeros.

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
private:
    int pow(int x, int n, int MOD) {
        int ans = 1;
        x %= MOD;

        while (n > 0) {
            if (n & 1) {
                ans = (ans * x) % MOD;
            }

            x = (x * x) % MOD;
            n >>= 1;
        }

        return ans;
    }

public:
    int superPow(int a, vector<int>& b) {

        if (a == 1) {
            return 1;
        }

        int num = 0;

        for (int val : b) {
            num = (num * 10 + val) % 1140;
        }

        // b is positive, so remainder 0 means
        // the exponent is a positive multiple of 1140.
        if (num == 0) {
            num = 1140;
        }

        return pow(a, num, 1337);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
