# [964. Least Operators to Express Number](https://leetcode.com/problems/least-operators-to-express-number/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a single positive integer `x`, we will write an expression of the form `x (op1) x (op2) x (op3) x ...` where each operator `op1`, `op2`, etc. is either addition, subtraction, multiplication, or division (`+`, `-`, `*`, or `/)`. For example, with `x = 3`, we might write `3 * 3 / 3 + 3 - 3` which is a value of 3.

When writing such an expression, we adhere to the following conventions:

- The division operator (`/`) returns rational numbers.

- There are no parentheses placed anywhere.

- We use the usual order of operations: multiplication and division happen before addition and subtraction.

- It is not allowed to use the unary negation operator (`-`). For example, "`x - x`" is a valid expression as it only uses subtraction, but "`-x + x`" is not because it uses negation.

We would like to write an expression with the least number of operators such that the expression equals the given `target`. Return the least number of operators used.

 

**Example 1:**

```
Input: x = 3, target = 19
Output: 5
Explanation: 3 * 3 + 3 * 3 + 3 / 3.
The expression contains 5 operations.
```

**Example 2:**

```
Input: x = 5, target = 501
Output: 8
Explanation: 5 * 5 * 5 * 5 - 5 * 5 * 5 + 5 / 5.
The expression contains 8 operations.
```

**Example 3:**

```
Input: x = 100, target = 100000000
Output: 3
Explanation: 100 * 100 * 100 * 100.
The expression contains 3 operations.
```

 

**Constraints:**

- `2 <= x <= 100`

- `1 <= target <= 2 * 108`

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    Map<Integer,Integer> dp = new HashMap<>();
    public int leastOpsExpressTarget(int x, int target) {
        if (dp.containsKey(target)) {
            return dp.get(target);
        }
        if (x > target) {
            dp.put(target, Math.min(target * 2 - 1, (x - target) * 2));
            return dp.get(target);
        }
        int times = 0;
        long sum = x;
        while (sum < target) {
            times++;
            sum *= x;
        }
        int subtract = Integer.MAX_VALUE;
        if (sum - target < target) {
            subtract = leastOpsExpressTarget(x, (int)(sum - target)) + times;
        }
        int add = leastOpsExpressTarget(x, target - (int)(sum / x)) + times - 1;
        dp.put(target, Math.min(subtract, add) + 1);
        return dp.get(target);
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
