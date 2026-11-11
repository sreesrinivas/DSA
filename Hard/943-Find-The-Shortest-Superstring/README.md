# [943. Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of strings `words`, return *the smallest string that contains each string in* `words` *as a substring*. If there are multiple valid strings of the smallest length, return **any of them**.

You may assume that no string in `words` is a substring of another string in `words`.

 

**Example 1:**

```
Input: words = ["alex","loves","leetcode"]
Output: "alexlovesleetcode"
Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
```

**Example 2:**

```
Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc"
```

 

**Constraints:**

- `1 <= words.length <= 12`

- `1 <= words[i].length <= 20`

- `words[i]` consists of lowercase English letters.

- All the strings of `words` are **unique**.

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution(object):
    def shortestSuperstring(self, A):
        """
        :type A: List[str]
        :rtype: str
        """
        def overlap(p, n):
            l=min(len(p), len(n))
            for i in range(l-1, -1, -1):
                if p[len(p)-i:]==n[:i]:
                    return i
            return 0
                    
        l=len(A)
        dist=[[0]*l for _ in range(l)]
        for i in range(l):
            for j in range(i+1, l):
                dist[i][j]=overlap(A[i], A[j])
                dist[j][i]=overlap(A[j], A[i])
                
        dp=[[0]*l for _ in range(1<<l)] # total overlap
        parent=[[None]*l for _ in range(1<<l)]
        
        for mask in range(1<<l):
            for bit in range(l):
                if mask&(1<<bit):
                    pmask=mask^(1<<bit)
                    if pmask==0:
                        continue
                    for pbit in range(l):
                        if pmask&(1<<pbit):
                            if dp[pmask][pbit]+dist[pbit][bit]>=dp[mask][bit]:
                                dp[mask][bit]=dp[pmask][pbit]+dist[pbit][bit]
                                parent[mask][bit]=pbit
                                        
        mask=(1<<l)-1
        bit=dp[mask].index(max(dp[mask]))
        idxList=[]
        while bit is not None:
            idxList.append(bit)
            bit, mask=parent[mask][bit], mask^(1<<bit)
        idxList=idxList[::-1]
        
        resList=[]
        for i in range(len(idxList)):
            if i==0:
                resList.append(A[idxList[i]])
            else:
                resList.append(A[idxList[i]][dist[idxList[i-1]][idxList[i]]:])
        return ''.join(resList)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
