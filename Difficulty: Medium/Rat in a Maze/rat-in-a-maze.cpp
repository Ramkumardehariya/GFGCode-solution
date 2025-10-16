class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<int>> &vis){
        if((x >= 0 && x < maze.size()) && (y >= 0 && y < maze[0].size()) && (vis[x][y] == 0) && maze[x][y] == 1){
            return true;
        }
        return false;
    }
    void solve(int x, int y,vector<vector<int>> &maze, vector<vector<int>> &vis, vector<string> &ans, string path){
        if(x == maze.size()-1 && y == maze[0].size()-1){
            ans.push_back(path);
            return;
        }
        vis[x][y] = 1;
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, maze, vis)){
            path.push_back('D');
            solve(newx, newy, maze, vis, ans, path);
            path.pop_back();
        }
        
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, maze, vis)){
            path.push_back('L');
            solve(newx, newy, maze, vis, ans, path);
            path.pop_back();
        }
        
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, maze, vis)){
            path.push_back('R');
            solve(newx, newy, maze, vis, ans, path);
            path.pop_back();
        }
        
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, maze, vis)){
            path.push_back('U');
            solve(newx, newy, maze, vis, ans, path);
            path.pop_back();
        }
        
        
        vis[x][y] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        int m = maze[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m, 0));

        solve(0, 0,maze, vis, ans, "");
        
        return ans;
    }
};