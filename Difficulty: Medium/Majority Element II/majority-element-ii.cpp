class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        vector<int> ans;
        map<int,int> mp;
        
        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        int n = arr.size();
        float check = n/3;

        for(auto it: mp){
            if(it.second > check){
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
    }
};