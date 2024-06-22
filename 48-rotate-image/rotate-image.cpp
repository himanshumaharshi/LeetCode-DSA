class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // firstly transpose the given matrix
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // now reverse every row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};