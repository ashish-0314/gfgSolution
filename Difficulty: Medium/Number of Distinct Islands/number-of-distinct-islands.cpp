// User function Template for C++

class Solution {
  public:
  
    void dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& vis , vector<pair<int,int>> &vec, int baserow , int basecol){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j]=1;
        vec.push_back({i-baserow, j - basecol});
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        for(int k = 0 ;k < 4 ; k++){
            int nr = i+delrow[k];
            int nc = j+delcol[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1) dfs(nr,nc,grid,vis,vec,baserow,basecol);
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
