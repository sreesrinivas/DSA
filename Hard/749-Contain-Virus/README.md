# [749. Contain Virus](https://leetcode.com/problems/contain-virus/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as an `m x n` binary grid `isInfected`, where `isInfected[i][j] == 0` represents uninfected cells, and `isInfected[i][j] == 1` represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two **4-directionally** adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There **will never be a tie**.

Return *the number of walls used to quarantine all the infected regions*. If the world will become fully infected, return the number of walls used.

 

**Example 1:**

```
Input: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
Output: 10
Explanation: There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
```

**Example 2:**

```
Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.
```

**Example 3:**

```
Input: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.
```

 

**Constraints:**

- `m == isInfected.length`

- `n == isInfected[i].length`

- `1 <= m, n <= 50`

- `isInfected[i][j]` is either `0` or `1`.

- There is always a contiguous viral region throughout the described process that will **infect strictly more uncontaminated squares** in the next round.

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
    int ans=0;
    int [] dr={-1,1,0,0};
    int[] dc={0,0,-1,1};
    int m;
    int n;
    public int containVirus(int[][] isIn) {

        this.m=isIn.length;
        this.n=isIn[0].length;
        while(true){
            boolean [][] visited=new boolean[m][n];
            List<Set<Integer>> components=new ArrayList<>();
            List<Set<Integer>> threats=new ArrayList<>();
            List<Integer> walls=new ArrayList<>();
            for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(!visited[i][j]&& isIn[i][j]==1){
                            Set<Integer> set=new HashSet<>();
                            
                            dfs(i,j,visited,isIn,set);// collect the components
                            components.add(set);
                            walls.add(Walls(set,isIn));// get number of walls need to block them
                            Set<Integer> aff=futureAffect(set,isIn);//get the area they would affect in future
                            threats.add(aff);
                        }
                    }
                }
                if(components.size()==0) break;// no components are there (all blocked)
                int ind=-1;
                int count=0;

                for(int i=0;i<threats.size();i++){
                    Set<Integer> threat=threats.get(i);
                    if(count<threat.size()){
                        count=threat.size();
                        ind=i;
                    }

                }  
                if(count==0) break; // the surroundings of the blocked area (area which has more threats)has no unaffected area (all are affected or blocked)
                
                ans+=walls.get(ind);// add the walls of the area which will affect more

                for(int area:components.get(ind)){
                int nr=area/n;
                int nc=area%n;
                    isIn[nr][nc]=-1; 
                }// block the area which affects more with -1 so we wont use this component again

                for(int i=0;i<threats.size();i++){
                    if(i==ind) continue;
                    Set<Integer> threat=threats.get(i);
                    for(int area:threat){
                        int nr=area/n;
                        int nc=area%n;
                        isIn[nr][nc]=1; 
                    }
                }// make the virus spread 
                
        
        }
       

    return ans;

        
    }

    public int Walls(Set<Integer> set,int[][] isIn){
       int w=0;

       for(int cell:set){
          int r=cell/n;
          int c=cell%n;
           for(int i=0;i<4;i++){
              int nr=r+dr[i];
              int nc=c+dc[i];

              if(nr>=0&&nr<m&&nc>=0&&nc<n&&isIn[nr][nc]==0){
                w++;
              }
           }
       } 
       return w;
    }

    public Set<Integer> futureAffect(Set<Integer> set,int[][] isIn){
    
     Set<Integer> affect=new HashSet<>();
       for(int cell:set){
          int r=cell/n;
          int c=cell%n;
           for(int i=0;i<4;i++){
              int nr=r+dr[i];
              int nc=c+dc[i];

              if(nr>=0&&nr<m&&nc>=0&&nc<n&&isIn[nr][nc]==0){
                 affect.add(nr*n+nc);
              }
           }
       } 
       return affect;
    }

    public void dfs(int i,int j, boolean [][] visited,int[][] isIn, Set<Integer> set){
            visited[i][j]=true;
            set.add(i*n+j);
             for(int r=0;r<4;r++){
                int nr=i+dr[r];
                int nc=j+dc[r];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&!visited[nr][nc]&&isIn[nr][nc]==1){
                    dfs(nr,nc,visited,isIn,set);
                }
             }        
    }

    
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
