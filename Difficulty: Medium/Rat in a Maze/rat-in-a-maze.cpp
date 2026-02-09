class Solution {
  public:
    void solve(vector<vector<int>> &maze, vector<string> &ans, vector<vector<bool>> &vis, string path, int i, int j, int n){
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        vis[i][j] = true;
        //down
        int srcx = i+1;
        int srcy = j;
        if(srcx < n && !vis[srcx][srcy] && maze[srcx][srcy] == 1){
            path.push_back('D');
            solve(maze, ans, vis,path, srcx, srcy, n);
            path.pop_back();
        }
        
        //Left
        srcx = i;
        srcy = j-1;
        if(srcy >= 0 && !vis[srcx][srcy] && maze[srcx][srcy] == 1){
            path.push_back('L');
            solve(maze, ans, vis, path, srcx, srcy, n);
            path.pop_back();
        }
        
        
        //right
        srcx = i;
        srcy = j+1;
        if(srcy < n && !vis[srcx][srcy] && maze[srcx][srcy] == 1){
            path.push_back('R');
            solve(maze, ans, vis,path, srcx, srcy, n);
            path.pop_back();
        }
        
        
        
        //up
        srcx = i-1;
        srcy = j;
        if(srcx >= 0 && !vis[srcx][srcy] && maze[srcx][srcy] == 1){
            path.push_back('U');
            solve(maze, ans, vis,path, srcx, srcy, n);
            path.pop_back();
        }
        
        vis[i][j] = false;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze.size();
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0){
            return ans;
        }
        
        vector<vector<bool>> vis(n,(vector<bool>(n, 0)));
        string path = "";
        solve(maze, ans, vis, path, 0, 0, n);
        return ans;
    }
};