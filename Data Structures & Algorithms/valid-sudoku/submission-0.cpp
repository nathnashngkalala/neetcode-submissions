class Solution {
public:
    /*
        you have a 9 x 9 sudoki board. 
        Valid if it follows sudoku rules
        you can divide into steps
        1. checking each row
        2. checking each cols
        3. checking each boxes -> this is tricky
            box is always 3 x 3 
            each itteration its row+3 and col+3
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        const int m = 9, n = 9;
        for(int r = 0; r < m; ++r) {
            vector<bool> seen(9, false);
            for(int c = 0; c < n; ++c) {
                if(!isdigit(board[r][c])) {
                    continue;
                }
                if(seen[board[r][c] - '0']) {
                    return false;
                }
                seen[board[r][c] - '0'] = true;
            }
        }
        for(int c = 0; c < n; ++c) {
            vector<bool> seen(9, false);
            for(int r = 0; r < m; ++r) {
                if(!isdigit(board[r][c])) {
                    continue;
                }
                if(seen[board[r][c] - '0']) {
                    return false;
                }
                seen[board[r][c] - '0'] = true;
            }
        }
        for(int r = 0; r < m; r += 3) {
            for(int c = 0; c < n; c += 3) {
                vector<bool> seen(9, false);
                for(int i = 0; i < 3; ++i) {
                    for(int j = 0; j < 3; ++j) {
                        int nr = r + i;
                        int nc = c + j;
                        if(!isdigit(board[nr][nc])) {
                            continue;
                        }
                        if(seen[board[nr][nc] - '0']) {
                            return false;
                        }
                        seen[board[nr][nc] - '0'] = true;
                    }   
                }
            }
        }
        return true;
    }
};
