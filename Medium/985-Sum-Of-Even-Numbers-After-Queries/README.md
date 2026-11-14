# [985. Sum of Even Numbers After Queries](https://leetcode.com/problems/sum-of-even-numbers-after-queries/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums` and an array `queries` where `queries[i] = [vali, indexi]`.

For each query `i`, first, apply `nums[indexi] = nums[indexi] + vali`, then print the sum of the even values of `nums`.

Return *an integer array *`answer`* where *`answer[i]`* is the answer to the *`ith`* query*.

 

**Example 1:**

```
Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
Output: [8,6,2,4]
Explanation: At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
```

**Example 2:**

```
Input: nums = [1], queries = [[4,0]]
Output: [0]
```

 

**Constraints:**

- `1 <= nums.length <= 104`

- `-104 <= nums[i] <= 104`

- `1 <= queries.length <= 104`

- `-104 <= vali <= 104`

- `0 <= indexi < nums.length`

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
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int sum = 0, N = queries.size();
        for (int n : nums) {
            if (n % 2 == 0) sum += n;
        }
        
        vector<int> ans(N, 0);
        
        // Four cases to handle.
        for (int i = 0; i < N; i++) {
            int val = queries[i][0], index = queries[i][1];
            int oldValue = nums[index];
            nums[index] += val;
            
            bool wasEven = (oldValue % 2) == 0;
            bool nowEven = (nums[index] % 2 == 0);
            
            if (wasEven && nowEven) {
                sum += val;
                ans[i] = sum;
            } else if (!wasEven && nowEven) {
                sum += nums[index];
                ans[i] = sum;
            } else if (wasEven && !nowEven) {
                sum -= oldValue;
                ans[i] = sum;
            } else {
                ans[i] = sum;
            }
        }
        
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
