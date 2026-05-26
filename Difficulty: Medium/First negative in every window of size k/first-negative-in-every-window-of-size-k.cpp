class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        queue<int> q ;
        int i = 0 , j = 0 ;
        int n = arr.size();
        while(j<n){
            if(arr[j]<0) q.push(arr[j]);
            if(j-i+1==k){
                if(!q.empty()) ans.push_back(q.front());
                else ans.push_back(0);
                if(arr[i]<0) q.pop();
                i++;
            }
            j++;
        }
        return ans;
    }
};