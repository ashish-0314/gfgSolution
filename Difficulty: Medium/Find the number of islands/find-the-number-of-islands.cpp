class Solution {
  public:
  
    void bfs(int i , int j , vector<vector<int>> & vis , vector<vector<char>>& grid){
        vis[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int dr = -1 ; dr <= 1 ; dr++){
                for(int dc = -1 ; dc <= 1 ; dc++){
                    int nr = r + dr ;
                    int nc = c + dc ;
                    if(nr>= 0 && nr < n && nc >= 0 && nc <m && grid[nr][nc] =='L' && !vis[nr][nc]){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j]=='L'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};