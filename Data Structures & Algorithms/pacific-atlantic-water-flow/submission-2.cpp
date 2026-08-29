class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    
    void dfs(int x, int y, int n, int m, vector<vector<int>>& heights, vector<vector<int>>& visited) {
        
        visited[x][y] = 1;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                heights[nx][ny] >= heights[x][y] && visited[nx][ny] == 0) {
                
                dfs(nx, ny, n, m, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        
        
        for (int i = 0; i < n; i++) {
            if (!pacific[i][0]) dfs(i, 0, n, m, heights, pacific);
            if (!atlantic[i][m - 1]) dfs(i, m - 1, n, m, heights, atlantic);
        }
        
       
        for (int j = 0; j < m; j++) {
            if (!pacific[0][j]) dfs(0, j, n, m, heights, pacific);
            if (!atlantic[n - 1][j]) dfs(n - 1, j, n, m, heights, atlantic);
        }
        
        vector<vector<int>> ans;
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    ans.push_back({i, j}); 
                }
            }
        }
        
        return ans;
    }
};