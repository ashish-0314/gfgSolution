class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
            int n=arr.size();
            sort(arr.begin(),arr.end());
            arr.erase(unique(arr.begin(), arr.end()), arr.end());
            int s=arr.size();
            if (s<2)
                return -1;
            return arr[s-2];
        
    }
};