class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for(int r = 0;r<board.size();r++){
            for(int c = 0;c< board.size();c++){
                if(board[r][c]=='.') continue;

                int val = board[r][c]-'1';

                int box_index = 3*(r/3) + (c/3);

                if(rows[r][val] || col[c][val] || box[box_index][val]){
                    return false;
                }

                rows[r][val] = true;
                col[c][val] = true;
                box[box_index][val] = true;

            }
        }
        return true;
    }
};
