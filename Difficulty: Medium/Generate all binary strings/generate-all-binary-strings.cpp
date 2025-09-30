class Solution {
  public:
  
    void solve(vector<string> &ans, int i, int &n, string str){
        if(i == n){
            ans.push_back(str);
            return;
        }
        str.push_back('0');
        solve(ans, i+1, n, str);
        str.pop_back();
        str.push_back('1');
        solve(ans, i+1, n, str);
        str.pop_back();
    }
    vector<string> binstr(int n) {
        vector<string> ans;
        solve(ans, 0, n, "");
        
        return ans;
    }
};