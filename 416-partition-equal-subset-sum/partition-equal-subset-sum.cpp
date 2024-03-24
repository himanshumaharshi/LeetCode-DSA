class Solution {
public:
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

    bool memoizationSolve(int index, vector<int>& nums, int target,
                          vector<vector<int>> dp) {
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
        // bool ansRecursive = solveUsingRecursion(index, nums, target);
        // return ansRecursive;

        // -------- Dynamic Programming (Top Down Approach / Memoization)
        // -------- T.C ---> O(n), S.C ---> O(n + n) -> O(n) step 1: create dp
        // array
        // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // bool ansMemoization = memoizationSolve(index, nums, target, dp);
        // return ansMemoization;

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation)
        // -------- T.C ---> O(index * capacity), S.C ---> O(index * capacity)
        bool ansTabulation = tabulationSolve(nums, target);
        return ansTabulation;

        // -------- Space Optimized Approach 1 --------
        // T.C ---> O(index * capacity), S.C ---> O(capacity)
        // int ansOptimized = spaceOptimized(weight, value, index, capacity);
        // cout << ansOptimized << endl;
    }
};