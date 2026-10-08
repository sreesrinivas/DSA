# [273. Integer to English Words](https://leetcode.com/problems/integer-to-english-words/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Convert a non-negative integer `num` to its English words representation.

 

**Example 1:**

```
Input: num = 123
Output: "One Hundred Twenty Three"
```

**Example 2:**

```
Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
```

**Example 3:**

```
Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
```

 

**Constraints:**

- `0 <= num <= 231 - 1`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public String numberToWords(int num) {
    if(num == 0)
        return "Zero";
    String[] bigString = new String[]{"Thousand","Million","Billion"};
    String result =  numberToWordsHelper(num%1000);
    num = num/1000;
    if(num > 0 && num%1000>0){
        result = numberToWordsHelper(num%1000) + "Thousand " + result;
    }
    num = num/1000;
    if(num > 0 && num%1000>0){
        result = numberToWordsHelper(num%1000) + "Million " + result;
    }
    num = num/1000;
    if(num > 0){
        result = numberToWordsHelper(num%1000) + "Billion " + result;
    }
    return result.trim();
}

public String numberToWordsHelper(int num){
    String[] digitString = new String[]{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    String[] teenString = new String[]{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen","Eighteen", "Nineteen"};
    String[] tenString = new String[]{"","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    String result = "";
    if(num > 99){
        result += digitString[num/100] + " Hundred ";
    }
    num = num % 100;
    if(num < 20 && num > 9){
        result += teenString[num%10]+" ";
    }else{
        if(num > 19){
            result += tenString[num/10]+" ";
        }
        num = num % 10;
        if(num > 0)
            result += digitString[num]+" ";
    }
    return result;
}
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
