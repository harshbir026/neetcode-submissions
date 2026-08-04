class Solution {
   public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(vector<vector<char>>& grid, int& n, int& m, int& x, int& y,
             vector<vector<int>>& visited) {
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == '1' &&
                visited[nx][ny] == 0) {
                dfs(grid, n, m, nx, ny, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    dfs(grid, n, m, i, j, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};
