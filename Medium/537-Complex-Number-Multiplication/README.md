# [537. Complex Number Multiplication](https://leetcode.com/problems/complex-number-multiplication/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A complex number can be represented as a string on the form `"real+imaginaryi"` where:

- `real` is the real part and is an integer in the range `[-100, 100]`.

- `imaginary` is the imaginary part and is an integer in the range `[-100, 100]`.

- `i2 == -1`.

Given two complex numbers `num1` and `num2` as strings, return *a string of the complex number that represents their multiplications*.

 

**Example 1:**

```
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
```

**Example 2:**

```
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
```

 

**Constraints:**

- `num1` and `num2` are valid complex numbers.

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
    public String complexNumberMultiply(String num1, String num2) {
        String[] nums1 = num1.split("\\+");
        String[] nums2 = num2.split("\\+");

        StringBuilder output = new StringBuilder();

        int a = Integer.parseInt(nums1[0]);
        int b = Integer.parseInt(nums1[1].replace("i", ""));
        int c = Integer.parseInt(nums2[0]);
        int d = Integer.parseInt(nums2[1].replace("i", ""));

        int e = a * c;
        int f = b * d;
        int g = (a * d) + (b * c);
        int h = e - f;

        output.append(h);
        output.append("+");
        output.append(g);
        output.append("i");

        return output.toString();
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
