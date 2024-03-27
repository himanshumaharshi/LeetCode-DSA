class Solution {
public:
    int solveUsingRecursion(vector<int>& arr, map<pair<int, int>, int>& maxi,
                            int left, int right) {
        // base case
        if (left == right) {
            // we are at leaf node
            return 0;
        }

        int ans = INT_MAX;

        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                               solveUsingRecursion(arr, maxi, left, i) +
                               solveUsingRecursion(arr, maxi, i + 1, right));
        }

        return ans;
    }

    int memoizationSolve(vector<int>& arr, map<pair<int, int>, int>& maxi,
                            int left, int right, vector<vector<int>>& dp) {
        // base case
        if (left == right) {
            // we are at leaf node
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }

        int ans = INT_MAX;

        for (int i = left; i < right; i++) {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] +
                               memoizationSolve(arr, maxi, left, i, dp) +
                               memoizationSolve(arr, maxi, i + 1, right, dp));
        }

        dp[left][right] = ans;
        return dp[left][right];
    }

    int tabulationSolve(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        // create dp array
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int left = n - 1; left >= 0; left--) {
            for (int right = 0; right < n; right++) {
                if (left >= right) {
                    continue;
                }
                else {
                    int ans = INT_MAX;
                    for (int i = left; i < right; i++) {
                        // get the maximum product from left and right subtree
                        int maxLeftRight = maxi[{left, i}] * maxi[{i + 1, right}];
                        ans = min(ans, maxLeftRight + dp[left][i] + dp[i + 1][right]);
                    }
                    dp[left][right] = ans;
                }
            }
        }

        return dp[0][n - 1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        // pre-compute all the maximum values for the every range in array
        // created a new DS that provides the maximum element from the given
        // range in O(1) Time
        for (int i = 0; i < arr.size(); i++) {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        int n = arr.size();

        // -------- Recursive Approach --------
        // T.C ---> Exponential (2 ^ n), S.C ---> O(n²)
        // return solveUsingRecursion(arr, maxi, 0, n - 1);

        // -------- Dynamic Programming (Top Down Approach / Memoization)
        // -------- T.C ---> O(n²), S.C ---> O(n²) (recursive stack + dp array)
        // step 1: create dp array
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return memoizationSolve(arr, maxi, 0, n - 1, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation)
        // -------- T.C ---> O(n³), S.C ---> O(n²)
        return tabulationSolve(arr, maxi);
    }
};