class Solution {
public:
    pair<int, int> getCoordinates(map<pair<int, int>, int> &mapping, int target) {
        for (auto& ele: mapping) {
            if (ele.second == target) {
                ele.second = -1;
                return ele.first;
            }
        }
        return {-1, -1};
    }
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int, int>, int> mapping;
        int zero = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                mapping[{i, j}] = matrix[i][j];
                if (matrix[i][j] == 0) {
                    zero++;
                }
            }
        }
        while (zero--) {
            pair<int, int> coordinates = getCoordinates(mapping, 0);
            int row = coordinates.first;
            int col = coordinates.second;
            for (int i = 0; i < matrix[row].size(); ++i) {
                matrix[row][i] = 0;
            }
            for (int j = 0; j < matrix.size(); ++j) {
                matrix[j][col] = 0;
            }
        }
    }
};