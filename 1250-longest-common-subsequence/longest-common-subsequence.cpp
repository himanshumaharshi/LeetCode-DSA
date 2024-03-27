class Solution {
public:
    int solveUsingRecursion(string text1, string text2, int i, int j) {
        // base case
        if (i == text1.length()) {
            return 0;
        }
        if (j == text2.length()) {
            return 0;
        }
        
        int ans = 0;
        
        if (text1[i] == text2[j]) {
            // if characters of both strings at index i, j matches
            ans = 1 + solveUsingRecursion(text1, text2, i + 1, j + 1);
        }
        else {
            // if characters of both strings at index i, j doen not matches
            ans = 0 + max(solveUsingRecursion(text1, text2, i, j + 1), solveUsingRecursion(text1, text2, i + 1, j));
        }

        return ans;
    }

    int memoizationSolve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i == text1.length()) {
            return 0;
        }
        if (j == text2.length()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = 0;
        
        if (text1[i] == text2[j]) {
            // if characters of both strings at index i, j matches
            ans = 1 + memoizationSolve(text1, text2, i + 1, j + 1, dp);
        }
        else {
            // if characters of both strings at index i, j doen not matches
            ans = 0 + max(memoizationSolve(text1, text2, i, j + 1, dp), memoizationSolve(text1, text2, i + 1, j, dp));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int tabulationSolve(string& text1, string& text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        
        for (int i = text1.length() - 1; i >= 0; i--) {
            for (int j = text2.length() - 1; j >= 0; j--) {
                int ans = 0;
                if (text1[i] == text2[j]) {
                    // if characters of both strings at index i, j matches
                    ans = 1 + dp[i + 1][j + 1];
                }
                else {
                    // if characters of both strings at index i, j doen not matches
                    ans = 0 + max(dp[i][j + 1], dp[i + 1][j]);
                }
                dp[i][j] = ans;
            }
        }
        
        return dp[0][0];
    }

    int spaceOptimized(string& text1, string& text2) {
        vector<int> curr(text2.length() + 1, 0);
        vector<int> next(text2.length() + 1, 0);
        
        for (int i = text1.length() - 1; i >= 0; i--) {
            for (int j = text2.length() - 1; j >= 0; j--) {
                int ans = 0;
                if (text1[i] == text2[j]) {
                    // if characters of both strings at index i, j matches
                    ans = 1 + next[j + 1];
                }
                else {
                    // if characters of both strings at index i, j doen not matches
                    ans = 0 + max(curr[j + 1], next[j]);
                }
                curr[j] = ans;
            }
            // shifting
            next = curr;
        }
        
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;

        // -------- Recursive Approach --------
        // T.C ---> Exponential (2 ^ n), S.C ---> O(n * m)
        // return solveUsingRecursion(text1, text2, i, j);

        // -------- Dynamic Programming (Top Down Approach / Memoization) --------
        // T.C ---> O(n * m), S.C ---> O(n * m) (recursive stack + dp array)
        // step 1: create dp array
        // vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));
        // return memoizationSolve(text1, text2, i, j, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation) -------- 
        // T.C ---> O(n * m), S.C ---> O(n * m)
        // return tabulationSolve(text1, text2);

        // -------- Space Optimized Approach -------- 
        // T.C ---> O(n * m), S.C ---> O(2m) = O(m)
        return spaceOptimized(text1, text2);
    }
};