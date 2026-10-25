# [591. Tag Validator](https://leetcode.com/problems/tag-validator/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string representing a code snippet, implement a tag validator to parse the code and return whether it is valid.

A code snippet is valid if all the following rules hold:

- The code must be wrapped in a **valid closed tag**. Otherwise, the code is invalid.

- A **closed tag** (not necessarily valid) has exactly the following format : `<TAG_NAME>TAG_CONTENT</TAG_NAME>`. Among them, `<TAG_NAME>` is the start tag, and `</TAG_NAME>` is the end tag. The TAG_NAME in start and end tags should be the same. A closed tag is **valid** if and only if the TAG_NAME and TAG_CONTENT are valid.

- A **valid** `TAG_NAME` only contain **upper-case letters**, and has length in range [1,9]. Otherwise, the `TAG_NAME` is **invalid**.

- A **valid** `TAG_CONTENT` may contain other **valid closed tags**, **cdata** and any characters (see note1) **EXCEPT** unmatched `<`, unmatched start and end tag, and unmatched or closed tags with invalid TAG_NAME. Otherwise, the `TAG_CONTENT` is **invalid**.

- A start tag is unmatched if no end tag exists with the same TAG_NAME, and vice versa. However, you also need to consider the issue of unbalanced when tags are nested.

- A `<` is unmatched if you cannot find a subsequent `>`. And when you find a `<` or `</`, all the subsequent characters until the next `>` should be parsed as TAG_NAME (not necessarily valid).

- The cdata has the following format : `<![CDATA[CDATA_CONTENT]]>`. The range of `CDATA_CONTENT` is defined as the characters between `<![CDATA[` and the **first subsequent** `]]>`.

- `CDATA_CONTENT` may contain **any characters**. The function of cdata is to forbid the validator to parse `CDATA_CONTENT`, so even it has some characters that can be parsed as tag (no matter valid or invalid), you should treat it as **regular characters**.

 

**Example 1:**

```
Input: code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
Output: true
Explanation: 
The code is wrapped in a closed tag : <DIV> and </DIV>. 
The TAG_NAME is valid, the TAG_CONTENT consists of some characters and cdata. 
Although CDATA_CONTENT has an unmatched start tag with invalid TAG_NAME, it should be considered as plain text, not parsed as a tag.
So TAG_CONTENT is valid, and then the code is valid. Thus return true.
```

**Example 2:**

```
Input: code = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
Output: true
Explanation:
We first separate the code into : start_tag|tag_content|end_tag.
start_tag -> "<DIV>"
end_tag -> "</DIV>"
tag_content could also be separated into : text1|cdata|text2.
text1 -> ">>  ![cdata[]] "
cdata -> "<![CDATA[<div>]>]]>", where the CDATA_CONTENT is "<div>]>"
text2 -> "]]>>]"
The reason why start_tag is NOT "<DIV>>>" is because of the rule 6.
The reason why cdata is NOT "<![CDATA[<div>]>]]>]]>" is because of the rule 7.
```

**Example 3:**

```
Input: code = "<A>  <B> </A>   </B>"
Output: false
Explanation: Unbalanced. If "<A>" is closed, then "<B>" must be unmatched, and vice versa.
```

 

**Constraints:**

- `1 <= code.length <= 500`

- `code` consists of English letters, digits, `'<'`, `'>'`, `'/'`, `'!'`, `'['`, `']'`, `'.'`, and `' '`.

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
class Solution(object):
    def isValid(self, code):
        """
        :type code: str
        :rtype: bool
        """
        stack = []
        
        state = ["plain", "open", "close", "cdata"]
        curr = "plain"        
        
        open_tag = []
        close_tag = []
        
        idx = 0
        
        while idx < len(code):
            ch = code[idx]
                        
            if curr == "plain":
                if not stack and idx != 0:
                    # code is not in a closed tage
                    print('code is not in a closed tage')
                    return False
                
                if code[idx:idx+9] == "<![CDATA[":
                    curr = "cdata"
                    idx += 9
                    continue
                elif code[idx:idx+2] == '</':
                    curr = 'close'
                    idx += 2
                    continue
                elif ch == '<':
                    curr = "open"
                
            elif curr == "open":
                if ch == '>':
                    if len(open_tag) > 9 or len(open_tag) < 1:
                        print('open tag name length not valid')
                        return False
                    
                    stack.append("".join(open_tag))
                    open_tag = []
                    curr = 'plain'
                    idx += 1
                    continue
                
                if not ch.isupper():
                    print('open tag is not upper', ch)
                    return False
                
                open_tag.append(ch)
            
            elif curr == 'close':
                if ch == '>':
                    if len(close_tag) > 9 or len(close_tag) < 1:
                        print('close tag name length not valid')
                        return False
                    
                    close_tag_str = "".join(close_tag)
                    if not stack or close_tag_str != stack[-1]:
                        print('tag no match')
                        return False
                    else:
                        stack.pop()
                    
                    close_tag = []
                    curr = 'plain'
                    idx += 1
                    continue
                    
                if not ch.isupper():
                    print('close tag is not upper')
                    return False
                
                close_tag.append(ch)
                    
            elif curr == "cdata":
                if code[idx:idx+3] == ']]>':
                    idx += 3
                    curr = "plain"
                    continue
                    
            idx += 1
            
        print(curr)
                    
        if stack or curr != "plain":
            return False
        
        return True
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
