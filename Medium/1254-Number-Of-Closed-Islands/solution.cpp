class Solution {
public:
    int n, m;

    bool DFS(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        if(grid[i][j] == 1) return true;

        grid[i][j] = 1;
        bool right = DFS(i, j + 1, grid);
        bool down = DFS(i + 1, j, grid);
        bool left = DFS(i, j - 1, grid);
        bool up = DFS(i - 1, j, grid);

        return (up && down && left && right);
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && DFS(i, j, grid))
                    ans++;
            }
        }
        return ans;
    }
};
