class Solution {
public:
    bool check(vector<int>& arr1, vector<int>& arr2) {
        if (arr2[0] <= arr1[0] && arr2[1] <= arr1[1] && arr2[2] <= arr1[2]) {
            return true;
        }
        else {
            return false;
        }
    }

    int getMaxHeight(vector<vector<int>>& cuboids){
        int n = cuboids.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);
        
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                // include
                int include = 0;
                if (prev == -1 || check(cuboids[curr], cuboids[prev])) {
                    include = cuboids[curr][2] + nextRow[curr + 1];
                }

                // exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // T.C -> O(n²), S.C -> O(n)
        // sort every array
        for (auto &a: cuboids) {
            sort(a.begin(), a.end());
        }
        // sort the 2d array
        sort(cuboids.begin(), cuboids.end());

        // apply longest increasing subsequence logic
        return getMaxHeight(cuboids);
    }
};