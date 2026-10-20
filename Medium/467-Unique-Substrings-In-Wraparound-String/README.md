# [467. Unique Substrings in Wraparound String](https://leetcode.com/problems/unique-substrings-in-wraparound-string/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

We define the string `base` to be the infinite wraparound string of `"abcdefghijklmnopqrstuvwxyz"`, so `base` will look like this:

- `"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...."`.

Given a string `s`, return *the number of **unique non-empty substrings** of *`s`* are present in *`base`.

 

**Example 1:**

```
Input: s = "a"
Output: 1
Explanation: Only the substring "a" of s is in base.
```

**Example 2:**

```
Input: s = "cac"
Output: 2
Explanation: There are two substrings ("a", "c") of s in base.
```

**Example 3:**

```
Input: s = "zab"
Output: 6
Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.
```

 

**Constraints:**

- `1 <= s.length <= 105`

- `s` consists of lowercase English letters.

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
    int findSubstringInWraproundString(string p) {
        int ans=1,prev_ans=1;
        vector<int> arr(26,0);
        arr[p[0]-'a']=1;
        for (int i=1;i<p.size();i++){
            if ((p[i-1]-'a'+1)%26==p[i]-'a') // Checking for continuation
                prev_ans++;
            else
                prev_ans=1;
            if (arr[p[i]-'a']<prev_ans){
                ans+=prev_ans-arr[p[i]-'a'];
                arr[p[i]-'a']=prev_ans;
            }
        }
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
