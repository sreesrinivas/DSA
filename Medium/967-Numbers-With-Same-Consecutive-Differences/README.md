# [967. Numbers With Same Consecutive Differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given two integers n and k, return *an array of all the integers of length *`n`* where the difference between every two consecutive digits is *`k`. You may return the answer in **any order**.

Note that the integers should not have leading zeros. Integers as `02` and `043` are not allowed.

 

**Example 1:**

```
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
```

**Example 2:**

```
Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
```

 

**Constraints:**

- `2 <= n <= 9`

- `0 <= k <= 9`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
    
    vector<int> ans;
    
    void Solve(int len , int &k , int num, int digit)
    {
        // Base Case
        if(len == 0 )
        {
                ans.push_back(num);
           return ;
        }
        
        // Next Possible digits will have range from 0 - 9
        for(int i = 0 ; i<10 ; i++)
        {
            // Checking for given condition 
            if(abs(i-digit) == k)
                Solve(len-1 , k, num*10 + i, i);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        
        // First Digit will have range from  1 - 9 
        // We have passed digit as 4th variable to have the last inserted digit
        for(int i = 1 ; i<=9 ; i++)
        {
             Solve(n-1 , k, i, i);
        }
        
        return ans;
        
		// Pls Upvote If You Like It !!
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
