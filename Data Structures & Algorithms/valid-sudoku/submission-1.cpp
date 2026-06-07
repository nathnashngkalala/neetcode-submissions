class Solution {
public:
    /*
        have a 9x9 sudoku
        return true if valid, else not
        we do a linear check
        the row and cols and then boxes
        boxes is the tricky
        there are 9 boxes
        start from [0,0] -> [r + 3][c + 3]
            for each we then check the box 3x3 
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        //check rows
        int R = board.size(), C = board[0].size();
        for(int r = 0; r < R; ++r) {
            vector<bool> seen(9, false);
            for(int c = 0; c < C; ++c) {
                if(board[r][c] == '.') continue;
                int val = board[r][c] - '0';
                if(seen[val]) {
                    return false;
                }
                seen[val] = true;
            }
        }
        //check cols
        for(int c = 0; c < C; ++c) {
            vector<bool> seen(9, false);
            for(int r = 0; r < R; ++r) {
                if(board[r][c] == '.') continue;
                int val = board[r][c]  - '0';
                if(seen[val]) {
                    return false;
                }
                seen[val] = true;
            }
        }
        //check boxes
        for(int r = 0; r < R; r += 3) {
            for(int c = 0; c < C; c += 3) {
                vector<bool> seen(9, false);
                for(int i = 0; i < 3; ++i) {
                    for(int j = 0; j < 3; ++j) {
                        if(board[r + i][c + j] == '.') continue;
                        int val = board[r+i][c+j] - '0';
                        if(seen[val]) {
                            return false;
                        }
                        seen[val] = true;
                    }
                }
            }
        }
        return true;
    }
};
