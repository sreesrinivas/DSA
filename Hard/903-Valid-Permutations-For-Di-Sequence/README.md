# [903. Valid Permutations for DI Sequence](https://leetcode.com/problems/valid-permutations-for-di-sequence/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given a string `s` of length `n` where `s[i]` is either:

- `'D'` means decreasing, or

- `'I'` means increasing.

A permutation `perm` of `n + 1` integers of all the integers in the range `[0, n]` is called a **valid permutation** if for all valid `i`:

- If `s[i] == 'D'`, then `perm[i] > perm[i + 1]`, and

- If `s[i] == 'I'`, then `perm[i] < perm[i + 1]`.

Return *the number of **valid permutations** *`perm`. Since the answer may be large, return it **modulo** `109 + 7`.

 

**Example 1:**

```
Input: s = "DID"
Output: 5
Explanation: The 5 valid permutations of (0, 1, 2, 3) are:
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
```

**Example 2:**

```
Input: s = "D"
Output: 1
```

 

**Constraints:**

- `n == s.length`

- `1 <= n <= 200`

- `s[i]` is either `'I'` or `'D'`.

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
class Solution:
    def numPermsDISequence(self, s: str) -> int:
        #find the number of permuataion from 0 to n 
        seen=set()
        n=len(s)
        mod=10**9+7
        #the possbible numbers are  0 to n 
        #why is n<=200 ? 
        """
        dp[i]-> number of possible sequences saying 

        
        """
        #we may end at same idx at same prev in diff ways 
        #example 0 1 3  i i 
        #exampple 0 2 3  i i
        """ 
        @cache
        def dp(idx,prev):
            if idx==n+1:
                return 1 
            ans=0 
            for val in range(n+1):
                if val not in seen:
                    if idx>0:
                        if s[idx-1]=='D':
                            if val<prev:
                                seen.add(val)
                                ans+=dp(idx+1,val)
                                seen.remove(val)
                                ans%=(10**9+7)
                        elif s[idx-1]=='I':
                            if val>prev:
                                seen.add(val)
                                ans+=dp(idx+1,val)
                                seen.remove(val)
                                ans%=(10**9+7)
                    else:
                        seen.add(val)
                        ans+=dp(idx+1,val)
                        seen.remove(val)
                        ans%=(10**9+7)
            return ans%(10**9+7)
        ans=dp(0,-1)
        dp.cache_clear()
        return ans
        """
        #the above is working 
        #the above code is O(N**3) 
        #instead of tracking the values we used 
        #we do one thing 
        #updating the ranks 
        #as we observed we only need to keep track of the 
        #        prev_element(rank in old terms before the new one is inserted ),index 

        #so define the dp 
        #dp[i][j]-> is at index  i , j is it's rank 
        dp=[[0]*(n+1) for _ in range(n+1)]
        #the n is len of s 
        #so we have n+1 elements 
        #dp[i][j] now changed to ith index is in the permuation 
        #not in the string s 
        

        #ranking is starting from 0 
        dp[0][0]=1
        for i in range(1,n+1):
            prefix=[0]*(n+1)
            prefix[0]=dp[i-1][0]
            for x in range(1,n+1): 
                prefix[x]=(prefix[x-1]+dp[i-1][x])
                prefix[x]%=mod
            for j in range(i+1):
                if s[i-1]=='I':
                    #we need more than that of prev 
                    #so the rank of prev doesnot change
                    #this can be changed with prefix_sums 
                    """
                    for  k in range(j):
                        dp[i][j]+=dp[i-1][k]
                        dp[i][j]%=mod
                    """
                    dp[i][j]=(prefix[j-1] if j>0 else 0)
                else:
                    #this can be chaned with prefix sums 
                    """
                    for  k in range(j,i):
                        dp[i][j]+=dp[i-1][k]
                        dp[i][j]%=mod
                    """
                    dp[i][j]=prefix[i-1]-(prefix[j-1] if j>0 else 0)
        return sum(dp[n])%(mod)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
