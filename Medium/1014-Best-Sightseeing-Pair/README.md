# [1014. Best Sightseeing Pair](https://leetcode.com/problems/best-sightseeing-pair/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `values` where values[i] represents the value of the `ith` sightseeing spot. Two sightseeing spots `i` and `j` have a **distance** `j - i` between them.

The score of a pair (`i < j`) of sightseeing spots is `values[i] + values[j] + i - j`: the sum of the values of the sightseeing spots, minus the distance between them.

Return *the maximum score of a pair of sightseeing spots*.

 

**Example 1:**

```
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
```

**Example 2:**

```
Input: values = [1,2]
Output: 2
```

 

**Constraints:**

- `2 <= values.length <= 5 * 104`

- `1 <= values[i] <= 1000`

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
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int>& a);
};

int Solution :: maxScoreSightseeingPair(vector<int>& a)
{
    int n = a.size();
    int maxOverallGain = INT_MIN;
    int maxEndRight = a[n-1] - (n-1);
    for(int i=n-2; i>=0; i--)
    {
        maxEndRight = max(maxEndRight, a[i+1] - (i+1));
        maxOverallGain = max(maxOverallGain, a[i] + i + maxEndRight);
    }
    return maxOverallGain;
    
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
