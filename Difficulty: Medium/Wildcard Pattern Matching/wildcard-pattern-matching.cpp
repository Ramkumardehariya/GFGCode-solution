class Solution {
  public:
  
    bool solve(int i, int j, string &txt, string &pat, vector<vector<int>> &dp){
        if(i == txt.length() && j == pat.length()){
            return true;
        }
        else if(i < txt.length() && j == pat.length()){
            return false;
        }
        else if(i == txt.length() ){
            for(int k = j; k<pat.length(); k++){
                if(pat[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(pat[j] == txt[i] || pat[j] == '?'){
            return dp[i][j] = solve(i+1, j+1, txt, pat, dp);
        }
        else if(pat[j] == '*'){
            return dp[i][j] = solve(i+1, j, txt, pat, dp) || solve(i, j+1, txt, pat, dp);
        }
        else{
            return false;
        }
        
    }
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size();
        int m = pat.size();
        vector<vector<int>> dp(n+1,vector<int>(m, -1));
        
        return solve(0, 0, txt, pat, dp);
    }
};