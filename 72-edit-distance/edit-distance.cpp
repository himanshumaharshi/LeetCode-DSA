class Solution {
public:
    int solveUsingRecursion(string& word1, string& word2, int i, int j) {
        // base case
        if (i >= word1.length()) {
            return word2.length() - j;
        }
        if (j >= word2.length()) {
            return word1.length() - i;
        }

        int ans = 0;
        if (word1[i] == word2[j]) {
            ans = solveUsingRecursion(word1, word2, i + 1, j + 1);
        }
        else {
            int insert = 1 + solveUsingRecursion(word1, word2, i, j + 1);
            int remove = 1 + solveUsingRecursion(word1, word2, i + 1, j);
            int replace = 1 + solveUsingRecursion(word1, word2, i + 1, j + 1);

            ans = min(insert, min(remove, replace));
        }
        return ans;
    }

    int memoizationSolve(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        // base case
        if (i >= word1.length()) {
            return word2.length() - j;
        }
        if (j >= word2.length()) {
            return word1.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if (word1[i] == word2[j]) {
            ans = memoizationSolve(word1, word2, i + 1, j + 1, dp);
        }
        else {
            int insert = 1 + memoizationSolve(word1, word2, i, j + 1, dp);
            int remove = 1 + memoizationSolve(word1, word2, i + 1, j, dp);
            int replace = 1 + memoizationSolve(word1, word2, i + 1, j + 1, dp);

            ans = min(insert, min(remove, replace));
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        if (word1.length() == 0) {
            return word2.length();
        }
        if (word2.length() == 0) {
            return word1.length();
        }

        // two pointers to traverse over words
        int i = 0;
        int j = 0;

        // -------- Recursive Approach --------
        // T.C ---> Exponential (2 ^ n), S.C ---> O(n * m)
        // return solveUsingRecursion(word1, word2, i, j);

        // -------- Dynamic Programming (Top Down Approach / Memoization) --------
        // T.C ---> O(n * m), S.C ---> O(n * m) (recursive stack + dp array)
        // step 1: create dp array
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return memoizationSolve(word1, word2, i, j, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation) -------- 
        // T.C ---> O(n * m), S.C ---> O(n * m)
        // return tabulationSolve(word1, word2);

        // -------- Space Optimized Approach -------- 
        // T.C ---> O(n * m), S.C ---> O(2m) = O(m)
        // return spaceOptimized(word1, word2);
    }
};