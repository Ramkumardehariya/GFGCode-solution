class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int num = mat[i][j];
                bool up = true;
                bool down = true;
                bool left = true;
                bool right = true;
                
                //up
                if(i > 0 && num < mat[i-1][j]){
                    up = false;
                }
                //left
                if(j > 0 && num < mat[i][j-1]){
                    left = false;
                }
                //down
                if(i < n-1 && num < mat[i+1][j]){
                    down = false;
                }
                //right
                if(j < m-1 && num < mat[i][j+1]){
                    right = false;
                }
                
                if(up && down && left && right){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return {-1,-1};
    }
};
