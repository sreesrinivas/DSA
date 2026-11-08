# [798. Smallest Rotation with Highest Score](https://leetcode.com/problems/smallest-rotation-with-highest-score/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Rust](https://img.shields.io/badge/Language-Rust-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an array `nums`. You can rotate it by a non-negative integer `k` so that the array becomes `[nums[k], nums[k + 1], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1]]`. Afterward, any entries that are less than or equal to their index are worth one point.

- For example, if we have `nums = [2,4,1,3,0]`, and we rotate by `k = 2`, it becomes `[1,3,0,2,4]`. This is worth `3` points because `1 > 0` [no points], `3 > 1` [no points], `0 <= 2` [one point], `2 <= 3` [one point], `4 <= 4` [one point].

Return *the rotation index *`k`* that corresponds to the highest score we can achieve if we rotated *`nums`* by it*. If there are multiple answers, return the smallest such index `k`.

 

**Example 1:**

```
Input: nums = [2,3,1,4,0]
Output: 3
Explanation: Scores for each k are listed below: 
k = 0,  nums = [2,3,1,4,0],    score 2
k = 1,  nums = [3,1,4,0,2],    score 3
k = 2,  nums = [1,4,0,2,3],    score 3
k = 3,  nums = [4,0,2,3,1],    score 4
k = 4,  nums = [0,2,3,1,4],    score 3
So we should choose k = 3, which has the highest score.
```

**Example 2:**

```
Input: nums = [1,3,0,2,4]
Output: 0
Explanation: nums will always have 3 points no matter how it shifts.
So we will choose the smallest k, which is 0.
```

 

**Constraints:**

- `1 <= nums.length <= 105`

- `0 <= nums[i] < nums.length`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.rs)**

```rust
struct Fenwick {
    bits: Vec<i32>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Fenwick {
            bits: vec![0; n + 1 + 100000],
        }
    }

    pub fn add(&mut self, mut idx: i32, mut val: i32) {
        while idx < self.bits.len() as i32 {
            self.bits[idx as usize] += val as i32;
            idx += idx & -idx;
        }
    }
    
    pub fn search(&self, mut idx: i32) -> i32 {
        let mut res: i32 = 0;
        while idx > 0 {
            res += self.bits[idx as usize] as i32;
            idx -= idx & -idx;
        }
        return res;
    }
}

impl Solution {
    pub fn best_rotation(nums: Vec<i32>) -> i32 {
        let n: usize = nums.len();
        let mut nums1: Vec<i32> = Vec::new();
        let mut fenwick: Fenwick = Fenwick::new(n);
        
        for i in 0..n {
            nums1.push(nums[i]);
        }
        for i in 0..n {
            nums1.push(nums[i]);
        }

        let mut total: i32 = 0;
        
        for i in 0..n {
            let diff = (i as i32) - nums[i];
            if diff < 0 {
                continue;
            }
            fenwick.add(diff + 1, 1);
            total += 1;
            
        }
        
        let mut bestidx: i32 = 0;
        let mut bestnum: i32 = total - fenwick.search(0);
        
        for i in 1..n {
            let diffo = (i - 1) as i32 - nums1[i - 1];
            if diffo >= 0 {
               fenwick.add(diffo + 1, -1);
               total -= 1;
            }
            
            let diffi = (i + n - 1) as i32 - nums1[i + n - 1];
            if diffi >= 0 {
                fenwick.add(diffi + 1, 1);
                total += 1;
            }
            
            let mut res: i32 = total - fenwick.search(i as i32);
            if res > bestnum {
                bestnum = res;
                bestidx = i as i32;
            }
        }
        return bestidx;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
