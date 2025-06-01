class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int k) {
       unordered_map<int,int>mp;
       for(auto x:mat2){
           for(auto y:x)mp[y]++;
       }
       int count = 0;
       for(auto x:mat1){
           for(auto y:x){
               count += mp[k-y];
           }
       }
       return count;
        
    }
};