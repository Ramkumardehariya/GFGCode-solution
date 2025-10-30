// User function Template for C++

class Solution {
  public:
  
    int solve(vector<int> &price, int sum, vector<int> &dp){
        if(sum < 0){
            return INT_MIN;
        }
        if(sum == 0){
            return 0;
        }
        
        if(dp[sum] != -1){
            return dp[sum];
        }
        int maxi = INT_MIN;
        for(int i = 1; i<=price.size(); i++){
            int ans = price[i-1]+solve(price, sum-i, dp);
            
            if(ans != INT_MIN){
                maxi = max(maxi, ans);
            }
        }
        
        return dp[sum] = maxi;
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, -1);
        return solve(price, n, dp);
        
    }
};