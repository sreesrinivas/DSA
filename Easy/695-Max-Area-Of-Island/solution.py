import sys

sys.setrecursionlimit(10000)


class Solution:
    def check(self, g: List[List[int]], i: int, j: int) -> int:
        if i == -1 or i == len(g) or j == -1 or j == len(g[0]) or not g[i][j]:
            return 0
        g[i][j] = 0
        return (
            1
            + self.check(g, i - 1, j)
            + self.check(g, i, j - 1)
            + self.check(g, i + 1, j)
            + self.check(g, i, j + 1)
        )

    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        mx = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    mx = max(mx, self.check(grid, i, j))
        return mx
