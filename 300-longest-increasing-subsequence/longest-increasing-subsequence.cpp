class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int curr, int prev){
        // base case
        if (curr >= nums.size()) {
            return 0;
        }

        // include
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) { // subsequence array is empty 
            include = 1 + solveUsingRecursion(nums, curr + 1, curr);
        }

        // exclude
        int exclude = 0 + solveUsingRecursion(nums, curr + 1, prev);

        int ans = max(include, exclude);
        return ans;
    }

    int memoizationSolve(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp){
        // base case
        if (curr >= nums.size()) {
            return 0;
        }

        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }

        // include
        int include = 0;
        if (prev == -1 || nums[curr] > nums[prev]) { // subsequence array is empty 
            include = 1 + memoizationSolve(nums, curr + 1, curr, dp);
        }

        // exclude
        int exclude = 0 + memoizationSolve(nums, curr + 1, prev, dp);

        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    int tabulationSolve(vector<int>& nums){
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        int n = nums.size();
        
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                // include
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) { // subsequence array is empty 
                    include = 1 + dp[curr + 1][curr + 1];
                }

                // exclude
                int exclude = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // -------- Recursive Approach --------
        // T.C ---> Exponential (2 ^ n), S.C ---> O(n * m)
        // return solveUsingRecursion(nums, curr, prev);

        // -------- Dynamic Programming (Top Down Approach / Memoization) --------
        // T.C ---> O(n * m), S.C ---> O(n * m) (recursive stack + dp array)
        // step 1: create dp array
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        // return memoizationSolve(nums, curr, prev, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation) -------- 
        // T.C ---> O(n * m), S.C ---> O(n * m)
        return tabulationSolve(nums);

        // -------- Space Optimized Approach -------- 
        // T.C ---> O(n * m), S.C ---> O(2m) = O(m)
        // return spaceOptimized(nums);
    }
};