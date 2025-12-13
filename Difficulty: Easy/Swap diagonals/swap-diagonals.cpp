class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        int i = 0;
        int j = 0;
        int row = 0;
        int n = mat.size();
        int m = mat[0].size();
        int col = m-1;
        
        while(i < n && j < m){
            swap(mat[i][j], mat[row][col]);
            i++;
            j++;
            row++;
            col--;
        }
    }
};
