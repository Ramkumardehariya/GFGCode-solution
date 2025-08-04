class Solution {
  public:
    bool isSafe(vector<vector<int>> &vis, int n, int m, vector<vector<int>> &maze, int x, int y){
        if((x >= 0 && x <= n-1) && (y >= 0 && y <= m-1) && (vis[x][y] == 0) && maze[x][y] == 1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &maze,int n,int m, int x, int y, string path, vector<string> &ans,vector<vector<int>> &vis){
        if(x == n-1 && y == m-1){
            ans.push_back(path);
            return;
        }
        vis[x][y] = 1;
        
        //down
        int newX = x+1;
        int newY = y;
        
        if(isSafe(vis,n,m, maze, newX, newY)){
            path.push_back('D');
            solve(maze, n,m, newX, newY, path, ans, vis);
            path.pop_back();
        }
        
        //left
        newX = x;
        newY = y-1;
        if(isSafe(vis,n,m, maze, newX, newY)){
            path.push_back('L');
            solve(maze, n,m, newX, newY, path, ans, vis);
            path.pop_back();
        }
        
        //right
        newX = x;
        newY = y+1;
        if(isSafe(vis,n,m, maze, newX, newY)){
            path.push_back('R');
            solve(maze, n,m, newX, newY, path, ans, vis);
            path.pop_back();
        }
        //up
        newX = x-1;
        newY = y;
        
        if(isSafe(vis,n,m ,maze, newX, newY)){
            path.push_back('U');
            solve(maze, n,m, newX, newY, path, ans, vis);
            path.pop_back();
        }
        vis[x][y] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze.size();
        int m = maze[0].size();
        
        vector<vector<int>> vis= maze;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n;j++){
                vis[i][j] = 0;
            }
        }
        
        string path = "";
        
        solve(maze,n,m, 0, 0,path, ans, vis);
        return ans;
    }
};