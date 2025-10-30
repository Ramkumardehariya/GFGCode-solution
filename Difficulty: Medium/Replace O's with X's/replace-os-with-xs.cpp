class Solution {
  public:
    bool isSafe(int x, int y, int n, int m,vector<vector<char>>&grid,vector<vector<bool>> &vis){
        if((x >= 0 && x < n) && (y >= 0 && y < m) && (vis[x][y] == false) && grid[x][y] == 'O'){
            return true;
        }
        return false;
    }
    void solve(int i, int j, int n, int m, vector<vector<char>>&grid, vector<vector<bool>> &track,vector<vector<bool>> &vis){
        
        
        track[i][j] = true;
        vis[i][j] = true;
        
        //down
        int x = i+1;
        int y = j;
        if(isSafe(x, y, n, m, grid, vis)){
            solve(x, y, n, m, grid, track, vis);
        }
        //left
        x = i;
        y = j-1;
        if(isSafe(x, y, n, m, grid, vis)){
            solve(x, y, n, m, grid, track, vis);
        }
        //right
        x = i;
        y = j+1;
        if(isSafe(x, y, n, m, grid, vis)){
            solve(x, y, n, m, grid, track, vis);
        }
        //up
        x = i-1;
        y = j;
        if(isSafe(x, y, n, m, grid, vis)){
            solve(x, y, n,m, grid, track, vis);
        }
        
        vis[i][j] = false;
    }
    
    
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<bool>> track(n, vector<bool>(m, false));
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if((i == 0 || j == 0 || i == n-1 || j== m-1) &&(grid[i][j] == 'O') && track[i][j] == false){
                    solve(i, j, n, m, grid, track, vis);
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m;j++){
                if(track[i][j] == false){
                    grid[i][j] = 'X';
                }
            }
        }
        
    }
};