class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        for(int i = 0; i<n;i++){
            int row = i;
            int col = i;
            
            int zeroCount = 0;
            int oneCount = 0;
            
            for(int j = 0; j<n; j++){
                if(row != j && mat[row][j] == 0){
                    zeroCount++;
                }
            }
            
            for(int j = 0; j<n; j++){
                if(col != j && mat[j][col] == 1){
                    oneCount++;
                }
            }
            
            if(zeroCount == n-1 && oneCount == n-1){
                return i;
            }
        }
        return -1;
    }
};