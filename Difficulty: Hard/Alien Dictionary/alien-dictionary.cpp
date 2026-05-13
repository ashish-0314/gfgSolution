class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<set<int>> adj(26);
        vector<int> indegree(26,0);
        vector<int> present(26,0);
        
        for(auto & word : words){
            for(char ch : word) present[ch-'a']=1;
        }
        
        for(int i = 0 ; i < words.size()-1 ; i++){
            string s1=words[i];
            string s2=words[i+1];
            int len = min(s1.size(),s2.size());
            int found = 0 ;
            for(int j = 0 ; j < len ; j++){
                if(s1[j]!=s2[j]){
                    int u = s1[j]-'a';
                    int v = s2[j]-'a';
                    if(adj[u].find(v)==adj[u].end()){
                        adj[u].insert(v);
                        indegree[v]++;
                    }
                    
                    found=1;
                    break;
                }
            }
            if(!found && s1.size()>s2.size()) return "";
        }
        
        queue<int> q ;
        for(int i =0 ; i < 26 ; i++){
            if(present[i] && indegree[i]==0) q.push(i);
        }
        string ans ="";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans+=char(node+'a');
            for(auto & it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        int totalchars=0;
        for(int i = 0 ; i< 26 ; i++) totalchars+=present[i];
        if(ans.size() != totalchars) return "";
        return ans;
    }
};