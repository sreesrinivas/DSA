class Solution {
public:
    void f(int i,int j, vector<vector<int>>&grid,int color,int re)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=re)return;
        grid[i][j]=-re;
        
        f(i+1,j,grid,color,re);
        f(i-1,j,grid,color,re);
        f(i,j+1,grid,color,re);
        f(i,j-1,grid,color,re);
       
        if(i>0 && j>0 && i<grid.size()-1 && j<grid[0].size()-1 
           && grid[i+1][j]==-re && grid[i-1][j]==-re  && grid[i][j+1]==-re  && grid[i][j-1]==-re)grid[i][j]=re;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int re=grid[row][col];
        f(row,col,grid,color,re);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]<0)grid[i][j]=color;
            }
        }
        return grid;
    }
};
