class Solution {
  public:
  
    void dfsHelper(int st ,vector<vector<int>>& adj , vector<int> &vis , vector<int>& ans ){
        vis[st] = 1;
        ans.push_back(st);
        for(auto & it : adj[st]){
            if(!vis[it]){
                dfsHelper(it,adj,vis,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(adj.size(),0);
        int st = 0 ;
        vis[st] = 1;
        vector<int> ans;
        dfsHelper(st,adj,vis,ans);
        return ans;
        
    }
};