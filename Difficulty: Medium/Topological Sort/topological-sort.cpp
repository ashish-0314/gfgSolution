class Solution {
  public:
  
    void dfs(int node , vector<int>& vis , vector<vector<int>> &adj , stack<int> &st){
        vis[node]=1;
        for(auto &it : adj[node]){
            if(!vis[it]) dfs(it,vis,adj,st);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        stack<int> st;
        for(auto & e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        vector<int> vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]) dfs(i,vis,adj,st);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};