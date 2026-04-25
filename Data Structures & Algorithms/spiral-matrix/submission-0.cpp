class Solution {
public:
    /*
        m x n matrix of ints
        return in spiral order
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n, top = 0, bottom = m;
        vector<int> res;
        while(left < right && top < bottom) {
            for(int c = left; c < right; ++c) {
                res.push_back(matrix[top][c]);
            }
            ++top;
            for(int r = top; r < bottom; ++r) {
                res.push_back(matrix[r][right - 1]);
            }
            --right;
            if (!(left < right && top < bottom)) {
                break;
            }
            for(int c = right - 1; c >= left; --c) {
                res.push_back(matrix[bottom - 1][c]);
            }
            --bottom;
            for(int r = bottom - 1; r >= top; --r) {
                res.push_back(matrix[r][left]);
            }
            ++left;
        }
        return res;
    }
};
