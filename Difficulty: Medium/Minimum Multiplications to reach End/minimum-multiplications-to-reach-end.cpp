class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q ;
        q.push({start,0});
        vector<int> dist(1000,1e9);
        dist[start]=0;
        int mod = 1000;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node==end) return steps;
            for(auto & it : arr){
                int num = (it*node)%mod;
                if(steps+1 < dist[num]){
                    dist[num] = steps+1;
                    q.push({num,steps+1});
                }
            }
        }
        return -1;
    }
};