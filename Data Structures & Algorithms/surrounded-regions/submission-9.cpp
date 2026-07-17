class Solution {

     /* void dfs(int row,int col, vector<vector<char>>& board){
        int m = board.size(), n = board[0].size();
        if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') return;

        // if(board[row][col] == 'O') 
        board[row][col] = 'Y';

          dfs(row+1,col,board);
          dfs(row-1,col,board);
          dfs(row,col-1,board);
          dfs(row,col+1,board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size();
        for(int i = 0 ; i<m;i++){
            for(int j = 0; j<n;j++){
                if(i == 0 || i == m-1 || j ==0 || j == n-1) {
                  if(board[i][j] == 'O')  dfs(i,j,board);
                }
            }
        }
                  

         
        for(int i = 0; i<m;i++){
            for(int j = 0;j<n;j++){
                    if(board[i][j] == 'O') board[i][j] = 'X';

                    if(board[i][j] == 'Y'){
                        board[i][j] = 'O';
                    }
                }
            }
    } */
public:
    void solve(vector<vector<char>>&board){
        int m = board.size() , n = board[0].size();
        queue<pair<int,int>>q;
        for(int i = 0 ; i<m;i++){
            for(int j = 0; j<n;j++){
                if(i == 0 || i == m-1 || j ==0 || j == n-1) {
                  if(board[i][j] == 'O'){
                    q.push({i,j});
                    board[i][j] = 'Y';
                  }
                }
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        // int size = q.size();
        // for(int i = 0; i<size; i++){
        //     int size = q.size();
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int j = 0; j< 4;j++){
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(nr>=0 && nr< m && nc >=0 && nc < n && board[nr][nc] == 'O'){
                    board[nr][nc] = 'Y';
                    q.push({nr,nc});
                }
            }
        }

        for(int i =0;i<m;i++){
            for(int j =0; j<n;j++){
                    if(board[i][j] == 'O') board[i][j] = 'X';
                    if(board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
            

    }
};
