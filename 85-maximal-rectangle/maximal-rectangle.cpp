class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> table(matrix.size(), vector<int>(matrix[0].size()));

        int i, j, k, l, maxi = 0, counter1, counter2;

        for (i = 0; i < matrix.size(); i++) {
            table[i][0] = (matrix[i][0] == '1');
        }
        for (i = 0; i < matrix[0].size(); i++) {
            table[0][i] = (matrix[0][i] == '1');
        }

        for (i = 1; i < matrix.size(); i++) {
            for (j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    table[i][j] = min({table[i][j - 1], table[i - 1][j],
                                       table[i - 1][j - 1]}) +
                                  1;
                }
            }
        }

        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    counter1 = table[i][j] * table[i][j];
                    counter2 = table[i][j] * table[i][j];
                    for (k = i + 1; k < matrix.size() &&
                                    table[i][j] <= table[k][j] && table[k][j];
                         k++) {
                        counter1 += table[i][j];
                    }
                    for (l = j + 1; l < matrix[0].size() &&
                                    table[i][j] <= table[i][l] && table[i][l];
                         l++) {
                        counter2 += table[i][j];
                    }
                    maxi = max({counter1, counter2, maxi});
                }
            }
        }

        return maxi;
    }
};