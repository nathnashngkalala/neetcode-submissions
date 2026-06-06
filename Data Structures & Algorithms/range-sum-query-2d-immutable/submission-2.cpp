class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Padded with an extra row and column of zeros (size: (m + 1) x (n + 1))
        prefix.assign(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Smooth and readable—no bounds checking needed
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] 
                             - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Maps coordinates directly into the padded prefix matrix
        return prefix[row2 + 1][col2 + 1] 
             - prefix[row1][col2 + 1] 
             - prefix[row2 + 1][col1] 
             + prefix[row1][col1];
    }
};