# [932. Beautiful Array](https://leetcode.com/problems/beautiful-array/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

An array `nums` of length `n` is **beautiful** if:

- `nums` is a permutation of the integers in the range `[1, n]`.

- For every `0 <= i < j < n`, there is no index `k` with `i < k < j` where `2 * nums[k] == nums[i] + nums[j]`.

Given the integer `n`, return *any **beautiful** array *`nums`* of length *`n`. There will be at least one valid answer for the given `n`.

 

**Example 1:**

```
Input: n = 4
Output: [2,1,4,3]
```

**Example 2:**

```
Input: n = 5
Output: [3,1,2,5,4]
```

 

**Constraints:**

- `1 <= n <= 1000`

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
    vector<int> beautifulArray(int n) {
        vector<int>ans;
        ans.push_back(1);

        while(n > ans.size()){
            vector<int>temp;

            for(int i : ans){
                if(2*i - 1 <= n)
                    temp.push_back(2*i - 1);
            }

            for(int i : ans){
                if(2*i <= n)
                    temp.push_back(2*i);
            }

            ans = temp;
        }

        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
