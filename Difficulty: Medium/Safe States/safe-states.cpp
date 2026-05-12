class Solution {
  public:
  
    bool dfs(int node , vector<vector<int>> &adj ,vector<int> &vis , vector<int> &Pathvis, vector<int> &check){
        vis[node]=1;
        Pathvis[node]=1;
        check[node]=0;
        for(auto &it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,Pathvis,check)==true){
                    return true;
                }
            }else if(Pathvis[it]) return true;
        }
        check[node]=1;
        Pathvis[node]=0;
        return false;
    }
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto & e: edges){
            int u =e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V,0);
        vector<int> Pathvis(V,0);
        vector<int> check(V,0);
        vector<int> safe;
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]) dfs(i,adj,vis,Pathvis,check);
        }
        for(int i = 0 ; i < V ; i++){
            if(check[i]==1) safe.push_back(i);
        }
        return safe;
    }
};