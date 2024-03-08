class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int col = matrix.size();
        int row = matrix[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};