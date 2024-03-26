class Solution {
public:
    int solveUsingRecursion(int start, int end) {
        // base case
        if (start >= end) {
            return 0;
        }

        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(solveUsingRecursion(start, i - 1), solveUsingRecursion(i + 1, end)));
        }
        return ans;
    }

    int memoizationSolve(int start, int end, vector<vector<int>>& dp) {
        // base case
        if (start >= end) {
            return 0;
        }
        // step 3: check if answer already exists or not
        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = min(ans, i + max(memoizationSolve(start, i - 1, dp), memoizationSolve(i + 1, end, dp)));
        }

        // step 2: replace answer with dp array
        dp[start][end] = ans;
        return dp[start][end];
    }

    int tabulationSolve(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // check the range and flow of top down apporach the iterate and calculate answer accoringly
        for (int start = n; start >= 1; start--) {
            for (int end = 1; end <= n; end++) {
                if (start >= end)
                    continue;
                else {
                    int ans = INT_MAX;
                    for (int i = start; i <= end; i++)
                        ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));

                    // store answer in dp array
                    dp[start][end] = ans;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // -------- Recursive Approach --------
        // T.C ---> Exponential (2 ^ n), S.C ---> O(n²)
        // return solveUsingRecursion(1, n);

        // -------- Dynamic Programming (Top Down Approach / Memoization)
        // -------- T.C ---> O(n³), S.C ---> O(n²) (recursive stack + dp array)
        // step 1: create dp array
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return memoizationSolve(1, n, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation)
        // -------- T.C ---> O(n³), S.C ---> O(n²)
        return tabulationSolve(n);
    }
};