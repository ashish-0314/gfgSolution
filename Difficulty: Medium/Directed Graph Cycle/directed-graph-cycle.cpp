class Solution {
  public:
    bool dfs(int node ,vector<vector<int>> &adj , vector<int> & vis , vector<int> & Pathvis){
        vis[node]=1;
        Pathvis[node]=1;
        for(auto & it : adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,Pathvis)==true) return true;
            }
            else if (Pathvis[it]) return true;
        }
        Pathvis[node]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto & e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V,0);
        vector<int> Pathvis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]) if(dfs(i,adj,vis,Pathvis)==true) return true;
        }
        return false;
    }
};