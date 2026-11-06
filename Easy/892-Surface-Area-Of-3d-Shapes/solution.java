/*
    Explanation about calculation
    -----------------------------

    Total Area contributed by a cube -> 6 * 1 (according to discription [1 * 1 * 1])
    
    Common area when the cubes are placed on the top of each other (vertically) : 
        2 * (number_of_cubes - 1) -> 2 * (grid[i][j] - 1)
        
    so therefore, total surface area by a tower : (6 * grid[i][j] - 2 * (grid[i][j] - 1))
                                                : 4 * grid[i][j] + 2
                                                
    
    Also needs to subtract, adjacent hidden common area from total surface area calculated
    so far.
    
        adjacent_hidden_common_area_horizontally : 2 * min(cubes_cnt_in_first_tower, cubes_cnt_in_tower_next_to_first_tower)
                                                 : 2 * min(grid[i][j], grid[i][j + 1]) or
                                                 : 2 * min(grid[i][j], grid[i][j - 1]) based on implementation.
                                                 
        adjacent_hidden_common_area_vertically   : 2 * min(cubes_cnt_in_first_tower, cubes_cnt_in_tower_beneath_to_first_tower)
                                                 : 2 * min(grid[i][j], grid[i + 1][j]) or
                                                 : 2 * min(grid[i][j], grid[i - 1][j]) based on implementation.
*/

class Solution {
    public int surfaceArea(int[][] grid) {
        int n = grid.length, totSA = 0;
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < n; j += 1) {
                if(grid[i][j] > 0) totSA += (6 * grid[i][j] - 2 * (grid[i][j] - 1));
                if(i > 0) totSA -= 2 * Math.min(grid[i][j], grid[i - 1][j]);//vertically hidden common area
                if(j > 0) totSA -= 2 * Math.min(grid[i][j], grid[i][j - 1]);//horizontally hidden common area
            }
        }
        
        return totSA;
    }
}
