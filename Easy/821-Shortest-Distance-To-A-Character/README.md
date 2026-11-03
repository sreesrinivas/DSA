# [821. Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s` and a character `c` that occurs in `s`, return *an array of integers *`answer`* where *`answer.length == s.length`* and *`answer[i]`* is the **distance** from index *`i`* to the **closest** occurrence of character *`c`* in *`s`.

The **distance** between two indices `i` and `j` is `abs(i - j)`, where `abs` is the absolute value function.

 

**Example 1:**

```
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
```

**Example 2:**

```
Input: s = "aaab", c = "b"
Output: [3,2,1,0]
```

 

**Constraints:**

- `1 <= s.length <= 104`

- `s[i]` and `c` are lowercase English letters.

- It is guaranteed that `c` occurs at least once in `s`.

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
    vector<int> shortestToChar(string s, char c) {
        vector<int> ioc; // vector for storing the indexed of c present in s
        int n=s.length();
        
        vector<int>ans(n); // answer vector
        
        for(int i=0;i<n;++i){
            if(s[i]==c) 
                ioc.push_back(i);
        }
        
        int m=ioc.size(); // size of ioc vector
        int left=0,right=0;
        
        for(int i=0;i<n;++i){
            
            // if current index has crossed ioc[right] then,
            // we need to make the current left to right and 
            // increment current right for pointing to next index of ioc vector ( if exists )
            if(i>ioc[right]){
                left=right;
                if(right<m-1)
                    ++right;
            }
                        
            // difference = min(abs(right nearest 'c' - curr index),abs(left nearest 'c' - curr index))
            ans[i]=min(abs(ioc[right]-i),abs(ioc[left]-i)); 

        }
        
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
