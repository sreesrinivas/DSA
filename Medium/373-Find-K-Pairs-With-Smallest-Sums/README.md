# [373. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given two integer arrays `nums1` and `nums2` sorted in **non-decreasing order** and an integer `k`.

Define a pair `(u, v)` which consists of one element from the first array and one element from the second array.

Return *the* `k` *pairs* `(u1, v1), (u2, v2), ..., (uk, vk)` *with the smallest sums*.

 

**Example 1:**

```
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```

**Example 2:**

```
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
```

 

**Constraints:**

- `1 <= nums1.length, nums2.length <= 105`

- `-109 <= nums1[i], nums2[i] <= 109`

- `nums1` and `nums2` both are sorted in **non-decreasing order**.

- `1 <= k <= 104`

- `k <= nums1.length * nums2.length`

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
private:
    struct Compare {
        bool operator()(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
            return ((get<0>(t1) + get<1>(t1)) > (get<0>(t2) + get<1>(t2)));
        }
    };

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int, int>> ans;
        
        if(nums1.size() == 0 || nums2.size() == 0 || k == 0) return ans;
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, Compare> pq;
        
        for(int i = 0; i < min((int)nums1.size(), k); i++) pq.push(make_tuple(nums1[i], nums2[0], 0));
        
        while(k-- > 0 && !pq.empty()) {
            tuple<int, int, int> top = pq.top();
            ans.push_back(make_pair(get<0>(top), get<1>(top)));
            
            pq.pop();
            if(get<2>(top) + 1 < nums2.size())
                pq.push(make_tuple(get<0>(top), nums2[get<2>(top)+1], get<2>(top)+1));
        }
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
