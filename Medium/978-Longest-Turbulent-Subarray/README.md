# [978. Longest Turbulent Subarray](https://leetcode.com/problems/longest-turbulent-subarray/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `arr`, return *the length of a maximum size turbulent subarray of* `arr`.

A subarray is **turbulent** if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray `[arr[i], arr[i + 1], ..., arr[j]]` of `arr` is said to be turbulent if and only if:

- For `i <= k < j`:

	
`arr[k] > arr[k + 1]` when `k` is odd, and
`arr[k] < arr[k + 1]` when `k` is even.

- Or, for `i <= k < j`:
	
`arr[k] > arr[k + 1]` when `k` is even, and
`arr[k] < arr[k + 1]` when `k` is odd.

 

**Example 1:**

```
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
```

**Example 2:**

```
Input: arr = [4,8,12,16]
Output: 2
```

**Example 3:**

```
Input: arr = [100]
Output: 1
```

 

**Constraints:**

- `1 <= arr.length <= 4 * 104`

- `0 <= arr[i] <= 109`

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
    int maxTurbulenceSize(vector<int>& a) {
        
        int i,ans=1,len=1,n=a.size();
        
        
        for(i=0;i<n-1;i++){
            
            if( ( (i&1)  and a[i]<a[i+1] ) or ( (i%2==0) and a[i]>a[i+1] ) ){
                len++;
            }
            else{
                ans = max(ans, len);
                len = 1;
            }
        }
        
        ans = max(ans,len);
        len=1;
        for(i=0;i<n-1;i++){
            
            if( ((i&1)  and a[i]>a[i+1]) or ((i%2==0) and a[i]<a[i+1]) ){
                len++;
            }
            else{
                ans = max(ans, len);
                len = 1;
            }
        }
        
        ans = max(ans,len);
        
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
