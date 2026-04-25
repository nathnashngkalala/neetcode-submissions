class Solution {
public:
    /*
        got a 2d matrix contains 'X' and 'O'
        if O surrounded by X we change it 
        what if we start from border -> if touches border O cant be turned
        we signify it as '#' and we do a second pass where 
        # -> O 
        O -> X
        we can run any graph traversal algo from O on border
        O(m * n) will be our complexity
    */
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        queue<pair<int,int>> q;
        for(int c = 0; c < n; ++c) {
            if(board[0][c] == 'O') {
                q.push({0, c});
            }
            if(board[m-1][c] == 'O') {
                q.push({m - 1, c});
            }
        }
        for(int r = 1; r < m - 1; ++r) {
            if(board[r][0] == 'O') {
                q.push({r, 0});
            }
            if(board[r][n-1] == 'O') {
                q.push({r, n-1});
            }
        }
        // cout << q.size() << endl;
        while(q.size() > 0) {
            pair<int,int> curr = q.front();
            q.pop();
            board[curr.first][curr.second] = '#';
            int dx[4] = {0,0,-1,1};
            int dy[4] = {1,-1,0,0};
            for(int k = 0; k < 4; ++k) {
                int nx = dx[k] + curr.first;
                int ny = dy[k] + curr.second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                    q.push({nx, ny});
                }
            }
        }
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                // cout << r << " " << c << endl;
                if(board[r][c] == '#') {
                    board[r][c] = 'O';
                } else if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
