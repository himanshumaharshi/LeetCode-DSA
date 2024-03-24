class Solution {
public:
    int MOD = 1000000007;
    // solution using recursion which will give TLE
    int solveUsingRecursion(int n, int k, int target) {
        // base case
        if (n < 0)
            return 0;
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 && target != 0)
            return 0;
        if (n != 0 && target == 0)
            return 0;

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = ans + solveUsingRecursion(n - 1, k, target - i);
        }
        return ans;
    }

    // top down approach of dynamic programming
    long long int memoizationSolve(int n, int k, int target, vector<vector<long long int>>& dp) {
        // base case
        if (n < 0)
            return 0;
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 && target != 0)
            return 0;
        if (n != 0 && target == 0)
            return 0;

        // step 3: check if answer already exists or not
        if (dp[n][target] != -1)
            return dp[n][target];

        long long int ans = 0;
        for (int i = 1; i <= k; i++) {
            long long int recAns = 0;
            if (target - i >= 0)
                recAns = memoizationSolve(n - 1, k, target - i, dp);
            ans = (ans % MOD + recAns % MOD) % MOD;
        }

        // step 2: replace answer with dp array
        dp[n][target] = ans;
        return dp[n][target];
    }

    // bottom up approach of dynamic programming
    int tabulationSolve(int n, int k, int target) {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, 0));
        
        dp[0][0] = 1;

        for (int index = 1; index <= n; index++) {
            for (int t = 1; t <= target; t++) {
                long long int ans = 0;
                for (int i = 1; i <= k; i++) {
                    long long int recAns = 0;
                    if (t - i >= 0) {
                        recAns = dp[index - 1][t - i];
                    }
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                dp[index][t] = ans;
            }
        }
        return dp[n][target];
    }

    int spaceOptimized(int n, int k, int target) {
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        
        prev[0] = 1;

        for (int index = 1; index <= n; index++) {
            for (int t = 1; t <= target; t++) {
                long long int ans = 0;
                for (int i = 1; i <= k; i++) {
                    long long int recAns = 0;
                    if (t - i >= 0) {
                        recAns = prev[t - i];
                    }
                    ans = (ans % MOD + recAns % MOD) % MOD;
                }
                curr[t] = ans;
            }
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // -------- Recursive Approach --------
        // T.C ---> Exponential (2^n), S.C ---> O(n)
        // return solveUsingRecursion(n, k, target);

        // -------- Dynamic Programming (Top Down Approach / Memoization)
        // -------- T.C ---> O(n * k * target), S.C ---> O(n * target)
        // step 1: create dp array
        // vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));
        // return memoizationSolve(n, k, target, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation)
        // -------- T.C ---> O(n * k * target), S.C ---> O(n * target)
        // return tabulationSolve(n, k, target);

        // -------- Space Optimized Approach --------
        // T.C ---> O(n * k * target), S.C ---> O(target)
        return spaceOptimized(n, k, target);
    }
};