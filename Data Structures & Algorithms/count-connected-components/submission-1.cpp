class Solution {
public:
    void bfs(int node, vector<vector<int>>&adj,vector<int>&vis){
        vis[node]  = 1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int first = q.front();
            q.pop();

            for(auto&it : adj[first]){
                if(!vis[it]){
                    vis[it]  = 1;
                    q.push(it);
                }
            }
        }
    }
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        if(vis[node]) return;
        vis[node] = 1; 
        for(auto& it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
        
            
        
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        
            for(auto& e: edges){
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            int cnt = 0;
        for(int i = 0; i<n;i++){
            if(!vis[i]){
                cnt++;
                // bfs(i,adj,vis);
                dfs(i,adj,vis);
            }
        }

        return cnt;
    } 
};
