class Solution {

private: 
    void dfs(vector<vector<char>>&grid,int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col>= grid[0].size() || grid[row][col] == '0') return;

        grid[row][col] = '0';
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row+1,col);
        dfs(grid,row,col-1);
    }
public:

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n;++j){
                if(grid[i][j] == '1'){
                    ++cnt;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
};

