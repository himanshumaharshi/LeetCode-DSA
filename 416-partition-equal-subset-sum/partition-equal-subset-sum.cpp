class Solution {
public:
    // recursive approach (will give TLE error)
    bool solveUsingRecursion(int index, vector<int>& nums, int target) {
        // base case
        if (index >= nums.size()) {
            // index out of range
            return 0;
        }
        if (target < 0) {
            // the sum is negative
            return 0;
        }
        if (target == 0) {
            // target sum found
            return 1;
        }

        // include exclude call
        bool include =
            solveUsingRecursion(index + 1, nums, target - nums[index]);
        bool exclude = solveUsingRecursion(index + 1, nums, target);

        return (include || exclude);
    }

    // dynamic programming top down approach
    bool memoizationSolve(int index, vector<int>& nums, int target,
                          vector<vector<int>>& dp) {
        // base case
        if (index >= nums.size()) {
            // index out of range
            return 0;
        }
        if (target < 0) {
            // the sum is negative
            return 0;
        }
        if (target == 0) {
            // target sum found
            return 1;
        }
        // step 3: check if answer already exists or not
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        // include exclude call
        bool include = memoizationSolve(index + 1, nums, target - nums[index], dp);
        bool exclude = memoizationSolve(index + 1, nums, target, dp);

        // step 2: replace answer with dp array
        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    // dynamic programming bottom up approach
    bool tabulationSolve(vector<int>& nums, int target) {
        // step 1: create dp array
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, 0));

        // step 2: observe base case of recursive solution
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }

        // step 3: check the range and flow of top down apporach the iterate and calculate answer accoringly
        for (int index = nums.size() - 1; index >= 0; index--) {
            for (int key = 1; key <= target; key++) {
                bool include = 0;

                if (key - nums[index] >= 0) {
                    include = dp[index + 1][key - nums[index]];
                }

                bool exclude = dp[index + 1][key];
                
                // store answer in dp array
                dp[index][key] = (include || exclude);
            }
        }
        return dp[0][target];
    }

    // space optimized approach with two different arrays
    bool spaceOptimized(vector<int>& nums, int target) {
        // step 1: create dp array
        vector<bool> curr(target + 1, 0);
        vector<bool> next(target + 1, 0);

        // step 2: observe base case of recursive solution
        curr[0] = 1;
        next[0] = 1;

        // step 3: check the range and flow of top down apporach the iterate and calculate answer accoringly
        for (int index = nums.size() - 1; index >= 0; index--) {
            for (int key = 1; key <= target; key++) {
                bool include = 0;

                if (key - nums[index] >= 0) {
                    include = next[key - nums[index]];
                }

                bool exclude = next[key];
                
                // store answer in dp array
                curr[key] = (include || exclude);
            }
            // shifting
            next = curr;
        }
        return curr[target];
    }

    // space optimized approach with only one array
    bool spaceOptimized2(vector<int>& nums, int target) {
        // step 1: create dp array
        vector<bool> curr(target + 1, 0);

        // step 2: observe base case of recursive solution
        curr[0] = 1;

        // step 3: check the range and flow of top down apporach the iterate and calculate answer accoringly
        for (int index = nums.size() - 1; index >= 0; index--) {
            for (int key = target; key >= 1; key--) {
                bool include = 0;

                if (key - nums[index] >= 0) {
                    include = curr[key - nums[index]];
                }

                bool exclude = curr[key];
                
                // store answer in dp array
                curr[key] = (include || exclude);
            }
        }
        return curr[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum & 1) {
            // sum is odd means no equal subset sum is possible
            return false;
        }

        int target = sum / 2;
        int index = 0;

        // -------- Recursive Approach --------
        // T.C ---> Exponential (2^n), S.C ---> O(n)
        // return solveUsingRecursion(index, nums, target);

        // -------- Dynamic Programming (Top Down Approach / Memoization)
        // -------- T.C ---> O(n * m), S.C ---> O(n * m)
        // step 1: create dp array
        // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // return memoizationSolve(index, nums, target, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation)
        // -------- T.C ---> O(n * m), S.C ---> O(n * m)
        // return tabulationSolve(nums, target);

        // -------- Space Optimized Approach --------
        // T.C ---> O(n * m), S.C ---> O(m)
        // return spaceOptimized(nums, target);

        // -------- Space Optimized Approach 2 --------
        // T.C ---> O(n * m), S.C ---> O(m)
        return spaceOptimized2(nums, target);
    }
};