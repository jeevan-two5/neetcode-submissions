class Solution {
public:

    int dfs(int row, int col, vector<vector<int>>&grid,int &area){
        int m = grid.size(), n = grid[0].size();
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0 )  return 0;

        area++;
        grid[row][col] = 0;
        dfs(row-1,col,grid,area);
        dfs(row,col+1,grid,area);
        dfs(row+1,col,grid,area);
        dfs(row,col-1,grid,area);
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        int cnt = 0, area =0,maxi = 0;
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(grid[i][j] == 1){
                    //cnt++;
                    area =0;
                 
                maxi    = max(dfs(i,j,grid,area),maxi);
                   // area++;
                }
            }
        }
        return maxi;
    }
};
