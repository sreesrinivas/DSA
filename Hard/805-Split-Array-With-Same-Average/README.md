# [805. Split Array With Same Average](https://leetcode.com/problems/split-array-with-same-average/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums`.

You should move each element of `nums` into one of the two arrays `A` and `B` such that `A` and `B` are non-empty, and `average(A) == average(B)`.

Return `true` if it is possible to achieve that and `false` otherwise.

**Note** that for an array `arr`, `average(arr)` is the sum of all the elements of `arr` over the length of `arr`.

 

**Example 1:**

```
Input: nums = [1,2,3,4,5,6,7,8]
Output: true
Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
```

**Example 2:**

```
Input: nums = [3,1]
Output: false
```

 

**Constraints:**

- `1 <= nums.length <= 30`

- `0 <= nums[i] <= 104`

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
    #define ll long long

    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();

        int lh = n / 2;
        int rh = n - lh;

        vector<vector<ll>> leftSum(lh + 1), rightSum(rh + 1);

        for (int mask = 0; mask < (1 << lh); mask++) {
            ll sum = 0;
            int cnt = 0;

            for (int i = 0; i < lh; i++) {
                if (mask & (1 << i)) {
                    sum += nums[i];
                    cnt++;
                }
            }

            leftSum[cnt].push_back(sum);
        }

        for (int mask = 0; mask < (1 << rh); mask++) {
            ll sum = 0;
            int cnt = 0;

            for (int i = 0; i < rh; i++) {
                if (mask & (1 << i)) {
                    sum += nums[lh + i];
                    cnt++;
                }
            }

            rightSum[cnt].push_back(sum);
        }

        for (auto &v : rightSum)
            sort(v.begin(), v.end());

        ll total = accumulate(nums.begin(), nums.end(), 0LL);

        for (int k = 1; k <= n / 2; k++) {

            if ((total * k) % n != 0)
                continue;

            ll target = (total * k) / n;

            for (int lc = 0; lc <= min(k, lh); lc++) {

                int rc = k - lc;

                if (rc > rh)
                    continue;

                auto &vec = rightSum[rc];

                for (ll left : leftSum[lc]) {

                    ll need = target - left;

                    auto it = lower_bound(vec.begin(), vec.end(), need);

                    if (it != vec.end() && *it == need)
                        return true;
                }
            }
        }

        return false;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
