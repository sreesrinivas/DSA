# [907. Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of integers arr, find the sum of `min(b)`, where `b` ranges over every (contiguous) subarray of `arr`. Since the answer may be large, return the answer **modulo** `109 + 7`.

 

**Example 1:**

```
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

**Example 2:**

```
Input: arr = [11,81,94,43,3]
Output: 444
```

 

**Constraints:**

- `1 <= arr.length <= 3 * 104`

- `1 <= arr[i] <= 3 * 104`

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
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), ans = 0, MOD = 1e9 + 7;
        vector<int> NSE(n,-1), PSE(n,-1); //Next smaller element, previous smaller element

        //Populate NSE
        stack<int> s; //Stack of indexes of Monotonically increasing elements (Standard Problem)
        for(int i = 0;i<n;i++){
            if(!s.empty()){
                while(!s.empty() && arr[s.top()]>arr[i]){
                    NSE[s.top()] = i;
                    s.pop();
                }
            }
            if(!s.empty()){
                PSE[i] = s.top();
            }
            s.push(i);
        }

        //Commenting this but initially for clarity I populated this then decided to merge this with the above loop itself

        // //Populate PSE
        // stack<int> p; //Again, stack of Monotonically increasing elements seen so far
        // for(int i = 0;i<n;i++){
        //     while(!p.empty() && arr[p.top()]>arr[i]){
        //         p.pop();
        //     }
        //     if(!p.empty()){
        //         PSE[i] = p.top();
        //     }
        //     p.push(i);
        // }

        for(int i = 0;i<n;i++){
            long long L = PSE[i] == -1? i+1: i - PSE[i];
            long long R = NSE[i] == -1? n -i: NSE[i] - i;
            ans+=(L*R*arr[i]%MOD);
            ans%=MOD;
        }

        return ans;

    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
