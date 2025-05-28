class Solution {
    public boolean ValidCorner(int matrix[][]) {
        // Code here
        int n = matrix.length;
       int m = matrix[0].length;
       for(int i=0; i<m; i++){
           for(int j=i+1; j<m; j++){
               int cnt = 0;
               for(int row=0; row<n; row++){
                   if(matrix[row][i] == 1 && matrix[row][j] == 1){
                       cnt += 1;
                   }
                   if(cnt>=2){
                       return true;
                   }
               }
           }
       }
       return false;
    }
}