class NumMatrix {
private:
    vector<vector<int>> prefix;
    vector<vector<int>> mat;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Storing matrix and initializing prefix with the same dimensions
        mat = matrix;
        prefix.assign(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Your build formula:
                // prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i][j]
                
                int top = (i - 1 >= 0) ? prefix[i-1][j] : 0;
                int left = (j - 1 >= 0) ? prefix[i][j-1] : 0;
                int topLeft = (i - 1 >= 0 && j - 1 >= 0) ? prefix[i-1][j-1] : 0;
                
                prefix[i][j] = top + left - topLeft + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Your query formula:
        // sum[i][j] = prefix[r2][c2] - (prefix[r1-1][c2] + prefix[r2][c1-1] - prefix[r1-1][c1-1])
        
        int topSection = (row1 - 1 >= 0) ? prefix[row1-1][col2] : 0;
        int leftSection = (col1 - 1 >= 0) ? prefix[row2][col1-1] : 0;
        int overlapSection = (row1 - 1 >= 0 && col1 - 1 >= 0) ? prefix[row1-1][col1-1] : 0;
        
        return prefix[row2][col2] - (topSection + leftSection - overlapSection);
    }
};