class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        // code here
        unordered_map<int,bool> mp;
        
        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]] = true;
        }
        
        vector<int> ans;
        
        for(int i = low; i<=high; i++){
            if(!mp[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};