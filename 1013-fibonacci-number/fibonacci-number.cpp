class Solution {
public:
    // below is the recursive solution for the problem statement and it have high time complexity
    int recursiveSolve (int n) {
        // base case
        if (n == 1 || n == 0) {
            return n;
        }
        int ans = recursiveSolve(n - 1) + recursiveSolve(n - 2);
        return ans;
    }

    // below is the code implementation of the problem using topDown approach of Dynamic Programming as the Time Complexity will be lower than recursive code
    // recursion + memoization
    int topDownSolveDP (int n, vector<int> dp) {
        // base case
        if (n == 1 || n == 0) {
            return n;
        }

        // step 3: check if answer already exists or not
        if (dp[n] != -1) {
            return dp[n];
        }

        // step 2: replace answer with dp array
        dp[n] = topDownSolveDP(n - 1, dp) + topDownSolveDP(n - 2, dp);
        return dp[n];
    }

    // bottomUp (Tabulation Method) approach of Dynamic Programming
    int bottomDownSolveDP (int n) {
        // step 1: create dp array
        vector<int> dp(n + 1, -1);

        // step 2: observe base case of recursive solution
        dp[0] = 0;
        dp[1] = 1;
        if (n == 0)
            return dp[0];
        if (n == 1)
            return dp[1];

        // step 3: iterate and calculate answer
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int spaceOptimisedSolution (int n) {
        int prev2 = 0;
        int prev1 = 1;
        int curr;

        // handle edge cases
        if (n == 0)
            return prev2;
        if (n == 1)
            return prev1;

        // step 3: iterate and calculate answer
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            // shifting
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int fib(int n) {
        // -------- Recursive Approach --------
        // T.C ---> O(2 ^ n), S.C ---> O(n)
        // int ansRecursive = recursiveSolve(n);
        // return ansRecursive;

        // -------- Dynamic Programming (Top Down Approach) --------
        // T.C ---> O(n), S.C ---> O(n + n) = O(n)
        // step 1: create dp array
        // vector<int> dp(n + 1, -1);
        // int ansTopDown = topDownSolveDP(n, dp);
        // return ansTopDown;

        // -------- Dynamic Programming (Bottom Down Approach) --------
        // T.C ---> O(n), S.C ---> O(n)
        // int ansBottomUp = bottomDownSolveDP(n);
        // return ansBottomUp;

        // -------- Space Optimized Approacn --------
        // T.C ---> O(n), S.C ---> O(1)
        int ansSpaceOpt = spaceOptimisedSolution(n);
        return ansSpaceOpt;
    }
};