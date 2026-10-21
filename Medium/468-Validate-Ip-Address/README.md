# [468. Validate IP Address](https://leetcode.com/problems/validate-ip-address/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `queryIP`, return `"IPv4"` if IP is a valid IPv4 address, `"IPv6"` if IP is a valid IPv6 address or `"Neither"` if IP is not a correct IP of any type.

**A valid IPv4** address is an IP in the form `"x1.x2.x3.x4"` where `0 <= xi <= 255` and `xi` **cannot contain** leading zeros. For example, `"192.168.1.1"` and `"192.168.1.0"` are valid IPv4 addresses while `"192.168.01.1"`, `"192.168.1.00"`, and `"192.168@1.1"` are invalid IPv4 addresses.

**A valid IPv6** address is an IP in the form `"x1:x2:x3:x4:x5:x6:x7:x8"` where:

- `1 <= xi.length <= 4`

- `xi` is a **hexadecimal string** which may contain digits, lowercase English letter (`'a'` to `'f'`) and upper-case English letters (`'A'` to `'F'`).

- Leading zeros are allowed in `xi`.

For example, "`2001:0db8:85a3:0000:0000:8a2e:0370:7334"` and "`2001:db8:85a3:0:0:8A2E:0370:7334"` are valid IPv6 addresses, while "`2001:0db8:85a3::8A2E:037j:7334"` and "`02001:0db8:85a3:0000:0000:8a2e:0370:7334"` are invalid IPv6 addresses.

 

**Example 1:**

```
Input: queryIP = "172.16.254.1"
Output: "IPv4"
Explanation: This is a valid IPv4 address, return "IPv4".
```

**Example 2:**

```
Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
Output: "IPv6"
Explanation: This is a valid IPv6 address, return "IPv6".
```

**Example 3:**

```
Input: queryIP = "256.256.256.256"
Output: "Neither"
Explanation: This is neither a IPv4 address nor a IPv6 address.
```

 

**Constraints:**

- `queryIP` consists only of English letters, digits and the characters `'.'` and `':'`.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    string validIPAddress(string queryIP) {
        if(queryIP.empty()) return "Neither";
        int n=queryIP.size();
        int i4=0,i6=0;
        for(char &ch:queryIP){
            if(ch=='.')
            {
                i4=1;
                break;
            }
            else if(ch==':')
            {
                i6=1;
                break;
            }
        }
        string ans;
        int x=0;
        int c=0;
        if(i4==1)
        {
            if(!isdigit(queryIP[n-1]))
            return "Neither";
            queryIP+='.';
            for(int i=0;i<queryIP.size();i++){
                if(queryIP[i]=='.')
                {
                    string s=queryIP.substr(x,i-x);
                    if(s.empty())
                    return "Neither";
                    if(!regex_match(s,regex("[0-9]+")))
                    return "Neither";
                    if(s.size()>1 && s[0]=='0')
                    return "Neither";
                    if(s.size()>3)
                    return "Neither";
                    if(stod(s)>255)
                    return "Neither";
                    x=i+1;
                    c++;
                }
            }
            if(c==4)
            ans="IPv4";
            else
            ans="Neither";
        }
        else
        {
            if(!isdigit(queryIP[n-1]) && !isalpha(queryIP[n-1]))
            return "Neither";
            queryIP+=':';
            for(int i=0;i<queryIP.size();i++){
                if(queryIP[i]==':')
                {
                    c++;
                    string s=queryIP.substr(x,i-x);
                    int l=i-x;
                    x=i+1;
                    if(!regex_match(s,regex("[0-9a-fA-F]+")))
                    return "Neither";
                    if(l>=1 && l<=4){}
                    else
                    {
                        return "Neither";
                    }
                }
            }
            if(c==8)
            ans="IPv6";
            else
            ans="Neither";
        }
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
