class Solution {
  public:
    int solve(int W, vector<int> &val, vector<int> &wt, int index, vector<vector<int>> &dp){
        if(index == val.size() || W == 0){
            return 0;
        }
        
        int include = 0;
        
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        if(W >= wt[index]){
            include = val[index]+ solve(W-wt[index], val, wt, index+1, dp);
        }
        int exclude = solve(W, val, wt, index+1, dp);
        
        return dp[index][W] = max(include, exclude);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
        return solve(W, val, wt, 0, dp);
    }
};