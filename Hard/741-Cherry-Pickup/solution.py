class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        
        m = len(grid)
        n = len(grid[0])
        mem = [ [ [-2**31 for i in range(m)] for j in range(n) ] for k in range(m)]
        
        return max(0, self.dfs(grid, mem, m, n, 0, 0, 0, 0))
    
    def dfs(self, grid, mem, m, n, x1, y1, x2, y2):
        
        if x1>=m or x2>=m or y1 >= n or y2>=n or grid[x1][y1] == -1 or grid[x2][y2] == -1:
            return -2**31
        
        if mem[x1][y1][x2] != -2**31:
            return mem[x1][y1][x2]
        
        cherry = 0
        
        if grid[x1][y1] == 1:
            cherry+=1
        
        if x1!=x2 and grid[x2][y2] == 1:
            cherry+=1
            
        if x1==m-1 and y1==n-1:
            return cherry
        
        cherry += max(
            self.dfs(grid, mem, m, n, x1+1, y1, x2+1, y2),
            self.dfs(grid, mem, m, n, x1+1, y1, x2, y2+1),
            self.dfs(grid, mem, m, n, x1, y1+1, x2+1, y2),
            self.dfs(grid, mem, m, n, x1, y1+1, x2, y2+1),
            )
        
        mem[x1][y1][x2] = cherry
        
        return cherry
