class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int row[] = new int[grid.length];
        int col[] = new int[grid[0].length];
        int rowMax = Integer.MIN_VALUE;
        int colMax = Integer.MIN_VALUE;
        int buildingHeightIncreased = 0;

        for (int i = 0; i < grid.length; i++) {
            rowMax = Integer.MIN_VALUE;
            colMax = Integer.MIN_VALUE;

            for (int j = 0; j < grid[0].length; j++) {
                rowMax = grid[i][j] > rowMax ? grid[i][j] : rowMax;
                colMax = grid[j][i] > colMax ? grid[j][i] : colMax;
            }

            row[i] = rowMax;
            col[i] = colMax;
        }

        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[0].length; j++)
                buildingHeightIncreased += Math.min(row[i], col[j]) - grid[i][j];

        return buildingHeightIncreased;
    }
}
