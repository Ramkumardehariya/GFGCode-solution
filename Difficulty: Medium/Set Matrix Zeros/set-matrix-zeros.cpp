class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) 
    {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited=mat;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    for(int k=0;k<m;k++)
                    {
                        visited[i][k]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    for(int k=0;k<n;k++)
                    {
                        visited[k][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=visited[i][j];
            }
        }
        
    }
};