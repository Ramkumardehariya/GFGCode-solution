class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int> st;
        
        
        
        for(auto num: a){
            st.insert(num);
        }
        for(auto num: b){
            st.insert(num);
        }
        
        vector<int> ans(st.begin(), st.end());
        
        return ans;
    }
};