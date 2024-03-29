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

    int spaceOptimized(vector<int>& nums){
        vector<int> currRow(nums.size() + 1, 0);
        vector<int> nextRow(nums.size() + 1, 0);
        int n = nums.size();
        
        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                // include
                int include = 0;
                if (prev == -1 || nums[curr] > nums[prev]) { // subsequence array is empty 
                    include = 1 + nextRow[curr + 1];
                }

                // exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }

    int optimalSolution(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            // include
            if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);}
            else {
                // overwrite
                // find index of just bigger element
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // -------- Recursive Approach --------
        // T.C ---> Exponential (2 ^ n), S.C ---> O(n * m)
        // return solveUsingRecursion(nums, curr, prev);

        // -------- Dynamic Programming (Top Down Approach / Memoization) --------
        // T.C ---> O(n²), S.C ---> O(n² + n²) (n²)
        // step 1: create dp array
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        // return memoizationSolve(nums, curr, prev, dp);

        // -------- Dynamic Programming (Bottom Up Approach / Tabulation) -------- 
        // T.C ---> O(n²), S.C ---> O(n²)
        // return tabulationSolve(nums);

        // -------- Space Optimized Approach -------- 
        // T.C ---> O(n²), S.C ---> O(n)
        return spaceOptimized(nums);

        // -------- Space Optimized Approach -------- 
        // T.C ---> O(n log n), S.C ---> O(n)
        return optimalSolution(nums);
    }
};