class Solution {
  public:
  
  int f(int i,int sum,vector<vector<int>> &dp,vector<int> &v){
      if(sum==0){
          return 0;
      }
      if(i>=v.size()){
          return 1e5;
      }
      if(dp[i][sum]!=-1){
          return dp[i][sum];
      }
      if(v[i]<=sum){
          return dp[i][sum]=min(1+f(i,sum-v[i],dp,v),f(i+1,sum,dp,v));
      }else{
          return dp[i][sum]=f(i+1,sum,dp,v);
      }
  }
    int minSquares(int n) {
        // Code here
        int temp=n;
        // int count=0;
        vector<int> v;
        for(int i=n;i>=1;i--){
            if(i<=temp){
                int a=sqrt(i);
                if(a*a==i){
                  v.push_back(i);
                }
            }
        }
        // cout<<count;
        vector<vector<int>> dp(v.size(),vector<int>(n+1,-1));
        return f(0,temp,dp,v);
    }
};