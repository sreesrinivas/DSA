# [1106. Parsing A Boolean Expression](https://leetcode.com/problems/parsing-a-boolean-expression/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A **boolean expression** is an expression that evaluates to either `true` or `false`. It can be in one of the following shapes:

- `'t'` that evaluates to `true`.

- `'f'` that evaluates to `false`.

- `'!(subExpr)'` that evaluates to **the logical NOT** of the inner expression `subExpr`.

- `'&(subExpr1, subExpr2, ..., subExprn)'` that evaluates to **the logical AND** of the inner expressions `subExpr1, subExpr2, ..., subExprn` where `n >= 1`.

- `'|(subExpr1, subExpr2, ..., subExprn)'` that evaluates to **the logical OR** of the inner expressions `subExpr1, subExpr2, ..., subExprn` where `n >= 1`.

Given a string `expression` that represents a **boolean expression**, return *the evaluation of that expression*.

It is **guaranteed** that the given expression is valid and follows the given rules.

 

**Example 1:**

```
Input: expression = "&(|(f))"
Output: false
Explanation: 
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
```

**Example 2:**

```
Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
```

**Example 3:**

```
Input: expression = "!(&(f,t))"
Output: true
Explanation: 
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
```

 

**Constraints:**

- `1 <= expression.length <= 2 * 104`

- expression[i] is one following characters: `'('`, `')'`, `'&'`, `'|'`, `'!'`, `'t'`, `'f'`, and `','`.

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
    bool parse_or (vector<int> &res)
    {
        int mask = res[0];
        for(int i=1; i<res.size(); i++)
        {
            mask |= res[i];
        }
        return mask;
    }
    
    bool parse_and (vector<int> &res)
    {
        int mask = res[0];
        for(int i=1; i<res.size(); i++)
        {
            mask &= res[i];
        }
        return mask;
    }
    
public:
    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<int> st;
        for(int i =0; i<n; i++)
        {
            if(s[i] == ',') continue;
            if(s[i]==')')
            {
                vector<int> res;
                while(st.top()!='&' && st.top()!='|' && st.top()!='!')
                {
                    char c = st.top();
                    st.pop();
                    if(c=='t') res.push_back(1);
                    if(c=='f') res.push_back(0);
                }
                char c = st.top();
                st.pop();
                if(c=='&')
                {
                    if(parse_and(res)) st.push('t');
                    else st.push('f');
                }
                else if(c=='|') 
                {
                    if(parse_or(res)) st.push('t');
                    else st.push('f');
                }
                else if(c=='!')
                {
                    if(res[0] == 0) st.push('t'); 
                    else st.push('f');
                }
            }
            else st.push(s[i]);
        }
        return (st.top()=='t');
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
