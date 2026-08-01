class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& board, int delrow[], int delcol[]) {
                visited[row][col]=1;
                int m = board.size();
                int n = board[0].size();

                for(int i =0;i<4;i++){
                    int nrow = row+delrow[i];
                    int ncol = col+delcol[i];
                    if(nrow >=0 && nrow <m && ncol >= 0 && ncol < n && visited[nrow][ncol]==0 && board[nrow][ncol] == 'O'){
                        dfs(nrow,ncol,visited,board,delrow,delcol);
                    }
                }
             }
    void solve(vector<vector<char>>& board) {
        int delrow[4] = {0, 0, 1, -1};
        int delcol[4] = {1, -1, 0, 0};
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int j = 0; j < n;j++){
            if (visited[0][j] == 0 && board[0][j] == 'O') {
                dfs(0, j, visited, board, delrow, delcol);
            }
            if (visited[m - 1][j] == 0 && board[m - 1][j] == 'O') {
                dfs(m - 1, j, visited, board, delrow, delcol);
            }
        }
        for (int i = 0; i < m;i++){
            if (visited[i][0] == 0 && board[i][0] == 'O') {
                dfs(i, 0, visited, board, delrow, delcol);
            }
            if (visited[i][n - 1] == 0 && board[i][n - 1] == 'O') {
                dfs(i, n - 1, visited, board, delrow, delcol);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};