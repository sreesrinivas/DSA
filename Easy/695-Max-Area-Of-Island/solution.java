class Solution {
    int check(int[][] g, int i, int j) {
        if (i == -1 || i == g.length || j == -1 || j == g[0].length || g[i][j] == 0) return 0;
        g[i][j] = 0;
        return 1 + check(g, i - 1, j) + check(g, i, j - 1) + check(g, i + 1, j) + check(g, i, j + 1);
    }

    public int maxAreaOfIsland(int[][] grid) {
        int mx = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 0) mx = Math.max(mx, check(grid, i, j));
            }
        }
        return mx;
    }
}
