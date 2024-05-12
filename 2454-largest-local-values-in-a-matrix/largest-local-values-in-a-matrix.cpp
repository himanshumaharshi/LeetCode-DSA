class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        // get size of the grid
        int n = grid.size();

        // matrix to store the ans, of size (n - 2) x (n - 2)
        vector<vector<int>> matrix(n - 2, vector<int>(n - 2, 0));

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                int maxLocal = 0;
                // find max element from current 3 x 3 matrix
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        maxLocal = max(maxLocal, grid[k][l]);
                    }
                }

                // store the current max in ans matrix
                matrix[i - 1][j - 1] = maxLocal;
            }
        }
        return matrix;
    }
};