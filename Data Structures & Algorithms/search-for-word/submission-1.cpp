class Solution {
   public:
    bool helper(vector<vector<char>>& board, string word, int row, int col, int n, int m, int ind) {
        if (ind == word.size()) {
            return true;
        }
        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[ind]) {
            return false;
        }

        char original = board[row][col];
        board[row][col] = '*';

        bool found = helper(board, word, row + 1, col, n, m, ind + 1) ||
                     helper(board, word, row - 1, col, n, m, ind + 1) ||
                     helper(board, word, row, col - 1, n, m, ind + 1) ||
                     helper(board, word, row, col + 1, n, m, ind + 1);

        board[row][col] = original;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (helper(board, word, i, j, n, m, 0)) return true;
                }
            }
        }
        return false;
    }
};
