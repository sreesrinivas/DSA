# [831. Masking Personal Information](https://leetcode.com/problems/masking-personal-information/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given a personal information string `s`, representing either an **email address** or a **phone number**. Return *the **masked** personal information using the below rules*.

**Email address:**

An email address is:

- A **name** consisting of **at least** two uppercase and lowercase English letters, followed by

- The `'@'` symbol, followed by

- The **domain** consisting of uppercase and lowercase English letters with a dot `'.'` somewhere in the middle (not the first or last character).

To mask an email:

- The uppercase letters in the **name** and **domain** must be converted to lowercase letters.

- The middle letters of the **name** (i.e., all but the first and last letters) must be replaced by 5 asterisks `"*****"`.

**Phone number:**

A phone number is formatted as follows:

- The phone number contains 10-13 digits.

- The last 10 digits make up the **local number**.

- The remaining 0-3 digits, in the beginning, make up the **country code**.

- **Separation characters** from the set `{'+', '-', '(', ')', ' '}` separate the above digits in some way.

To mask a phone number:

- Remove all **separation characters**.

- The masked phone number should have the form:
	
`"***-***-XXXX"` if the country code has 0 digits.
`"+*-***-***-XXXX"` if the country code has 1 digit.
`"+**-***-***-XXXX"` if the country code has 2 digits.
`"+***-***-***-XXXX"` if the country code has 3 digits.

- `"XXXX"` is the last 4 digits of the **local number**.

 

**Example 1:**

```
Input: s = "LeetCode@LeetCode.com"
Output: "l*****e@leetcode.com"
Explanation: s is an email address.
The name and domain are converted to lowercase, and the middle of the name is replaced by 5 asterisks.
```

**Example 2:**

```
Input: s = "AB@qq.com"
Output: "a*****b@qq.com"
Explanation: s is an email address.
The name and domain are converted to lowercase, and the middle of the name is replaced by 5 asterisks.
Note that even though "ab" is 2 characters, it still must have 5 asterisks in the middle.
```

**Example 3:**

```
Input: s = "1(234)567-890"
Output: "***-***-7890"
Explanation: s is a phone number.
There are 10 digits, so the local number is 10 digits and the country code is 0 digits.
Thus, the resulting masked number is "***-***-7890".
```

 

**Constraints:**

- `s` is either a **valid** email or a phone number.

- If `s` is an email:
	
`8 <= s.length <= 40`
`s` consists of uppercase and lowercase English letters and exactly one `'@'` symbol and `'.'` symbol.

- If `s` is a phone number:
	
`10 <= s.length <= 20`
`s` consists of digits, spaces, and the symbols `'('`, `')'`, `'-'`, and `'+'`.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def maskPII(self, s: str) -> str:
        if "@" in s:
            name,domain=s.split("@")
            name=name.lower()
            domain=domain.lower()
            name=name[0]+"*****"+name[-1]
            return name+"@"+domain  
        else:
            gg=""
            for x in s:
                if x.isdigit():
                    gg+=x
            l=len(gg)
            if l>10:
                return "+"+"*"*(l-10)+"-***-***-"+gg[-4:]
            return "***-***-"+gg[-4:]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
