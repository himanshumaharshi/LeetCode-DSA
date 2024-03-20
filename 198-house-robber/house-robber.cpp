class Solution {
public:

    // below is the recursive solution for the problem statement and it have high time complexity and will give TLE
    int recursiveSolve(vector<int>& nums, int n) {
        // n -> index of current house
        // base case
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return nums[0];
        }

        // recursive calls for include and exclude operations on nums array
        int include = recursiveSolve(nums, n - 2) + nums[n];
        int exclude = recursiveSolve(nums, n - 1) + 0;

        return max(include, exclude);
    }

    // below is the code implementation of the problem using topDown approach of Dynamic Programming as the Time Complexity will be lower than recursive code
    // recursion + memoization
    int memoizationSolve(vector<int>& nums, int n, vector<int>& dp) {
        // base case
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return nums[0];
        }

        // step 3: check if answer already exists or not
        if (dp[n] != -1) {
            return dp[n];
        }

        // recursive calls for include and exclude operations on nums array
        int include = memoizationSolve(nums, n - 2, dp) + nums[n];
        int exclude = memoizationSolve(nums, n - 1, dp) + 0;

        // step 2: replace answer with dp array
        dp[n] = max(include, exclude);
        return dp[n];
    }

    // bottomUp (Tabulation Method) approach of Dynamic Programming
    int tabulationSolve(vector<int>& nums, int n) {
        // step 1: create dp array
        vector<int> dp(n + 1, 0);

        // step 2: observe base case of recursive solution
        dp[0] = nums[0];

        // step 3: check the range and flow of top down apporach the iterate and calculate answer accoringly
        for (int i = 1; i <= n; i++) {
            int temp = 0;
            if (i - 2 >= 0)
                temp = dp[i - 2];

            int include = temp + nums[i];
            int exclude = dp[i - 1] + 0;

            // store answer in dp array
            dp[i] = max(include, exclude);
        }
        return dp[n];
    }

    int spaceOptimizedSolution(vector<int>& nums, int n) {
        int prev2 = 0;
        int prev1 = nums[0];
        int curr = 0;

        for (int i = 1; i <= n; i++) {
            int temp = 0;
            if (i - 2 >= 0)
                temp = prev2;

            int include = temp + nums[i];
            int exclude = prev1 + 0;

            // store answer in dp array
            curr = max(include, exclude);
            // shifting of variables
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
    
        // -------- Recursive Approach --------
        // T.C ---> Exponential
        // return recursiveSolve(nums, n);

        // -------- Dynamic Programming (Top Down Approach) --------
        // T.C ---> O(n), S.C ---> O(n + n) = O(n)
        // step 1: create dp array
        // vector<int> dp(n + 1, -1);
        // return memoizationSolve(nums, n, dp);

        // -------- Dynamic Programming (Bottom Down Approach) --------
        // T.C ---> O(n), S.C ---> O(n)
        // return tabulationSolve(nums, n);

        // -------- Space Optimized Approacn --------
        // T.C ---> O(n), S.C ---> O(1)
        return spaceOptimizedSolution(nums, n);
    }
};