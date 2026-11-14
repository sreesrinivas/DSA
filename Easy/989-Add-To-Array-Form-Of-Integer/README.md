# [989. Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

The **array-form** of an integer `num` is an array representing its digits in left to right order.

- For example, for `num = 1321`, the array form is `[1,3,2,1]`.

Given `num`, the **array-form** of an integer, and an integer `k`, return *the **array-form** of the integer* `num + k`.

 

**Example 1:**

```
Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
```

**Example 2:**

```
Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
```

**Example 3:**

```
Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021
```

 

**Constraints:**

- `1 <= num.length <= 104`

- `0 <= num[i] <= 9`

- `num` does not contain any leading zeros except for the zero itself.

- `1 <= k <= 104`

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
    public List<Integer> addToArrayForm(int[] num, int k) {
        LinkedList<Integer> res=new LinkedList<>();
        int carry=0;
        int i=0;
		/*We always start computing from array's last element and k's last digit and will 
		compute sum and carry. We will iterate it till k and index of array both have existance. 
		If one of them gets exhausted the for loop below will not work.*/
        for(i=num.length-1;i>=0 && k>0;i--){
            int temp=num[i];
            res.addFirst((temp+carry+(k%10))%10);
            carry=(temp+carry+(k%10))/10;
            k/=10;
        }
		/*If for an instance your k is greater than the number that is present in the form of 
		array then the below while loop will work.*/
        while(k!=0){
            int compute=(k%10)+carry;
            res.addFirst(compute%10);
            carry=compute/10;
            k/=10;
        }
		/*If for an instance the number that is present in the form of array is greater than k 
		then the below for loop will work.*/
        for(int r=i;r>=0;r--){
            int temp=num[r];
            res.addFirst((temp+carry)%10);
            carry=(temp+carry)/10;
        }
		/*If there is some carry still remaining at last then add it to beginning of the 
		arraylist or linkedlist.*/
        if(carry!=0)
            res.addFirst(carry);
        return res;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
