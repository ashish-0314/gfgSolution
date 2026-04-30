class Solution {
  public:
  
    void dfs(int node , vector<vector<int>> &adj , vector<int> &vis ){
        vis[node]=1;
        for(auto & it : adj[node]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);
        int cnt = 0 ;
        for(int i =0 ; i < V ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};