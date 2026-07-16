class Solution {

public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;// ante pushing rotten oranges in this q

        
        
        int fresh = 0;
        for(int i = 0; i< m; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;

        while(!q.empty() && fresh >0){
            int q_size = q.size();

            for(int i  = 0; i < q_size;i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                int dr[] ={-1,1,0,0};
                int dc[] = {0,0,-1,1};

                for(int i = 0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr>=0 && nr < m && nc >=0 && nc <n && grid[nr][nc] == 1){
                        q.push({nr,nc});
                        grid[nr][nc] =2;
                        fresh--;
                    }
                }
                
            }

            if(!q.empty()) minutes++;
        }

        if(fresh) return -1;
        return minutes;
        https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/5daa219c-ae90-4027-41c3-6ea4d9158300/public$1
    }
};
