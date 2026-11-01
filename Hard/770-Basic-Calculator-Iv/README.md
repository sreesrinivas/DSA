# [770. Basic Calculator IV](https://leetcode.com/problems/basic-calculator-iv/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an expression such as `expression = "e + 8 - a + 5"` and an evaluation map such as `{"e": 1}` (given in terms of `evalvars = ["e"]` and `evalints = [1]`), return a list of tokens representing the simplified expression, such as `["-1*a","14"]`

- An expression alternates chunks and symbols, with a space separating each chunk and symbol.

- A chunk is either an expression in parentheses, a variable, or a non-negative integer.

- A variable is a string of lowercase letters (not including digits.) Note that variables can be multiple letters, and note that variables never have a leading coefficient or unary operator like `"2x"` or `"-x"`.

Expressions are evaluated in the usual order: brackets first, then multiplication, then addition and subtraction.

- For example, `expression = "1 + 2 * 3"` has an answer of `["7"]`.

The format of the output is as follows:

- For each term of free variables with a non-zero coefficient, we write the free variables within a term in sorted order lexicographically.
	
For example, we would never write a term like `"b*a*c"`, only `"a*b*c"`.

- Terms have degrees equal to the number of free variables being multiplied, counting multiplicity. We write the largest degree terms of our answer first, breaking ties by lexicographic order ignoring the leading coefficient of the term.
	
For example, `"a*a*b*c"` has degree `4`.

- The leading coefficient of the term is placed directly to the left with an asterisk separating it from the variables (if they exist.) A leading coefficient of 1 is still printed.

- An example of a well-formatted answer is `["-2*a*a*a", "3*a*a*b", "3*b*b", "4*a", "5*c", "-6"]`.

- Terms (including constant terms) with coefficient `0` are not included.
	
For example, an expression of `"0"` has an output of `[]`.

**Note:** You may assume that the given expression is always valid. All intermediate results will be in the range of `[-231, 231 - 1]`.

 

**Example 1:**

```
Input: expression = "e + 8 - a + 5", evalvars = ["e"], evalints = [1]
Output: ["-1*a","14"]
```

**Example 2:**

```
Input: expression = "e - 8 + temperature - pressure", evalvars = ["e", "temperature"], evalints = [1, 12]
Output: ["-1*pressure","5"]
```

**Example 3:**

```
Input: expression = "(e + 8) * (e - 8)", evalvars = [], evalints = []
Output: ["1*e*e","-64"]
```

 

**Constraints:**

- `1 <= expression.length <= 250`

- `expression` consists of lowercase English letters, digits, `'+'`, `'-'`, `'*'`, `'('`, `')'`, `' '`.

- `expression` does not contain any leading or trailing spaces.

- All the tokens in `expression` are separated by a single space.

- `0 <= evalvars.length <= 100`

- `1 <= evalvars[i].length <= 20`

- `evalvars[i]` consists of lowercase English letters.

- `evalints.length == evalvars.length`

- `-100 <= evalints[i] <= 100`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    Map<String,Integer> map=new HashMap<>(); //evaluation map
    class Term
    {
        int para=1; //the parameter of this term
        List<String> var=new ArrayList<>(); //each factor (e.a. a*b*b*c->{a,b,b,c})
        @Override
        public String toString()
        {
            if (para==0) return "";
            String ans="";
            for (String s:var) ans+="*"+s;
            return para+ans;
        }
        boolean equals(Term that)
        {
            if (this.var.size()!=that.var.size()) return false;
            for (int i=0;i<this.var.size();i++)
                if (!this.var.get(i).equals(that.var.get(i))) return false;
            return true;
        }
        int compareTo(Term that)
        {
            if (this.var.size()>that.var.size()) return -1;
            if (this.var.size()<that.var.size()) return 1;
            for (int i=0;i<this.var.size();i++)
            {
                int x=this.var.get(i).compareTo(that.var.get(i));
                if (x!=0) return x;
            }
            return 0;
        }
        Term times(Term that)
        {
            Term pro=new Term(this.para*that.para);
            for (String s:this.var) pro.var.add(new String(s));
            for (String s:that.var) pro.var.add(new String(s));
            Collections.sort(pro.var);
            return pro;
        }
        Term(int x) { para=x; }
        Term(String s) { if (map.containsKey(s)) para=map.get(s); else var.add(s); }
        Term(Term that) { this.para=that.para; this.var=new ArrayList<>(that.var); }
    }
    class Expression 
    {
        List<Term> list=new ArrayList<>(); //Term List
        char oper='+'; // Arithmetic symbol
        Expression(int x) { list.add(new Term(x)); }
        Expression(String s) { list.add(new Term(s)); }
        Expression(List<Term> l) { list=l; }
        Expression times(Expression that)
        {
            List<Term> c=new ArrayList<>();
            for (Term t1:this.list)
                for (Term t2:that.list)
                    c.add(t1.times(t2));
            c=combine(c);
            return new Expression(c);
        }
        Expression plus(Expression that,int sgn)
        {
            List<Term> c=new ArrayList<>();
            for (Term t:this.list) c.add(new Term(t));
            for (Term t:that.list) 
            {
                Term t2=new Term(t);
                t2.para=t2.para*sgn;
                c.add(t2);
            }
            c=combine(c);
            return new Expression(c);
        }
        Expression cal(Expression that)
        {
            if (oper=='+') return plus(that,1);
            if (oper=='-') return plus(that,-1);
            return times(that);
        }
        List<String> toList()
        {
            List<String> ans=new ArrayList<>();
            for (Term t:list) 
            {
                String s=t.toString();
                if (s.length()>0) ans.add(s);
            }
            return ans;
        }
    }  
    List<Term> combine(List<Term> a) //combine the similar terms
    {
        Collections.sort(a,(t1,t2)->(t1.compareTo(t2))); //sort all terms to make similar terms together
        List<Term> c=new ArrayList<>();
        for (Term t:a)
        {
            if (c.size()!=0 && t.equals(c.get(c.size()-1))) c.get(c.size()-1).para+=t.para;
            else c.add(new Term(t));
        }
        return c;
    }
    public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
        for (int i=0;i<evalvars.length;i++) map.put(evalvars[i],evalints[i]);
        int i=0,l=expression.length();
        Stack<Expression> stack=new Stack<>();
        Stack<Integer> priStack=new Stack<>();
        Expression zero=new Expression(0);
        stack.push(zero);
        priStack.push(0);
        int pri=0;
        while (i<l)
        {
            char ch=expression.charAt(i);
            if (Character.isDigit(ch))
            {
                int num=0;
                while (i<l && Character.isDigit(expression.charAt(i)))
                {
                    num=num*10+(expression.charAt(i)-48);
                    i++;
                }
                stack.add(new Expression(num));
                continue;
            }
            if (Character.isLetter(ch))
            {
                String s="";
                while (i<l && Character.isLetter(expression.charAt(i)))
                {
                    s+=expression.charAt(i);
                    i++;
                }
                stack.add(new Expression(s));
                continue;
            }
            if (ch=='(') pri+=2;
            if (ch==')') pri-=2;
            if (ch=='+' || ch=='-' || ch=='*')
            {
                int nowPri=pri;
                if (ch=='*') nowPri++;
                while (!priStack.isEmpty() && nowPri<=priStack.peek())
                {
                    Expression now=stack.pop(),last=stack.pop();
                    priStack.pop();
                    stack.push(last.cal(now));
                }
                stack.peek().oper=ch;
                priStack.push(nowPri);
            }
            i++;
        }
        while (stack.size()>1)
        {
            Expression now=stack.pop(),last=stack.pop();
            stack.push(last.cal(now));
        }
        return stack.peek().toList();
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
