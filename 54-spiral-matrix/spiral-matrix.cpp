class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;
        // T.C -> O(n * m), S.C -> O(n * m)
        while (top <= bottom && left <= right) {
            // traverse in right direction
            for (int i = left; i <= right; i++) 
                ans.push_back(matrix[top][i]);
            top++; // move top
            // traverse in bottom direction
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--; // move right
            // traverse in left direction
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--; // move bottom
            }
            // traverse in top direction
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};