class Solution {
  public:
    bool solve(int mid,vector<vector<int>> &matrix, int k){
        int cnt = 0;
        for(int i=0;i<matrix.size();i++){
            int le = upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            cnt+=le;
        }
        return cnt>=k;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        int res = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(solve(mid,matrix,k)){
                res = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return res;
    }
};