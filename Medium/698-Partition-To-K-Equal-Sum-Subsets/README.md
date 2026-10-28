# [698. Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.

 

**Example 1:**

```
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

**Example 2:**

```
Input: nums = [1,2,3,4], k = 3
Output: false
```

 

**Constraints:**

- `1 <= k <= nums.length <= 16`

- `1 <= nums[i] <= 104`

- The frequency of each element is in the range `[1, 4]`.

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> bucket_partial_sum(1 << n, 0); 
        int total_sum = 0; 
        for(int i = 0;i < n; i++){
            total_sum += nums[i]; 
        }
        if(total_sum % k) return false; 
        int t_sum = total_sum / k; 
        for(int i = 1;i < (1 <<n); i++){
            int sum = 0; 
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    sum += nums[j]; 
                }
            }
            bucket_partial_sum[i] = sum % t_sum; 
        }

        vector<bool> dp(1 << n, false); 
        dp[0] = true; 
        for(int mask = 1; mask < (1 << n); mask++){
            for(int i = 0;i < n; i++){
                if(!(mask & (1 << i))) continue; 

                int prev_mask = mask & (~(1 << i)); 
                if(dp[prev_mask] && (nums[i] + bucket_partial_sum[prev_mask] <= t_sum)){
                    dp[mask] = true; 
                }
            }
        }

        return dp[(1 << n) - 1]; 
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
