class Solution {
public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> board(n, vector<int>(n, -1));

        // Knight’s 8 possible moves
        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        // check if move is inside board and unvisited
        auto isSafe = [&](int x, int y) {
            return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
        };

        function<bool(int, int, int)> solve = [&](int x, int y, int step) {
            if (step == n * n) return true; // all cells visited

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (isSafe(nx, ny)) {
                    board[nx][ny] = step;
                    if (solve(nx, ny, step + 1))
                        return true;
                    board[nx][ny] = -1; // backtrack
                }
            }
            return false;
        };

        // start from (0,0)
        board[0][0] = 0;

        if (solve(0, 0, 1))
            return board;

        // No valid tour exists
        return {};
    }
};