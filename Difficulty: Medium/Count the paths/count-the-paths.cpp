class Solution {
  public:
  int dfs(int node,vector<vector<int>>&adj,int dest,vector<int>&dp){
      if(node==dest) return 1;
      if(dp[node]!=-1) return dp[node];
      int ans=0;
      for(auto child:adj[node]){
          ans=ans+dfs(child,adj,dest,dp);
      }
      return dp[node]=ans;
  }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
        }
        vector<int>dp(V,-1);
        return dfs(src,adj,dest,dp);
    }
};