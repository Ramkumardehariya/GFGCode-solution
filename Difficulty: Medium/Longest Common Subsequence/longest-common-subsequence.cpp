class Solution {
  public:
  
    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i == a.length() || j == b.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1+solve(i+1, j+1, a, b, dp);
        }
        else{
            ans = max(solve(i+1, j, a, b, dp), solve(i, j+1, a, b, dp));
        }
        
        return dp[i][j] = ans;
    }
    int lcs(string &s1, string &s2) {
        // code here
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return solve(0, 0, s1, s2, dp);
    }
};
