class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int i = 0;
        int j = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        while(i < n && j < m){
            int one = true;
            
            for(int k = 0; k<m; k++){
                if(i != k && mat[i][k] == 1){
                    one= false;
                }
            }
            
            int zero = true;
            for(int k = 0; k<n; k++){
                if(k != j && mat[k][j] == 0){
                    zero = false;
                }
            }
            
            if(zero && one){
                return i;
            }
            i++;
            j++;
        }
        
        return -1;
    }
};