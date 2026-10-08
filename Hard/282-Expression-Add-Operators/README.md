# [282. Expression Add Operators](https://leetcode.com/problems/expression-add-operators/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `num` that contains only digits and an integer `target`, return ***all possibilities** to insert the binary operators *`'+'`*, *`'-'`*, and/or *`'*'`* between the digits of *`num`* so that the resultant expression evaluates to the *`target`* value*.

Note that operands in the returned expressions **should not** contain leading zeros.

**Note** that a number can contain multiple digits.

 

**Example 1:**

```
Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
```

**Example 2:**

```
Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
```

**Example 3:**

```
Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
```

 

**Constraints:**

- `1 <= num.length <= 10`

- `num` consists of only digits.

- `-231 <= target <= 231 - 1`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
    public static void backtrack(String num,int tar,int index,long value,long prev, String expression ,List<String>ans){
        if(index==num.length()){
            if(value==tar){
                ans.add(expression);
            }
            return;
        }

        for(int i=index;i<num.length();i++){
            if(i>index && num.charAt(index)=='0'){
                break;
            }

            long curr=Long.parseLong(num.substring(index,i+1));

        if(index==0){
            backtrack(num,tar,i+1,curr,curr,expression+curr,ans);
        }else{
            backtrack(num,tar,i+1,value+curr,curr,expression+"+"+curr,ans);
        backtrack(num,tar,i+1,value-curr,-curr,expression+"-"+curr,ans);
        backtrack(num,tar,i+1,value-prev+prev*curr,prev*curr,expression+"*"+curr,ans);
    }
        }

    }
    public List<String> addOperators(String num, int target) {
        List<String>ans=new ArrayList<>();
        backtrack(num,target,0,0,0,"",ans);
        return ans;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
