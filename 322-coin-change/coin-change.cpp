class Solution {
public:
    // below is the recursive solution for the problem statement and it have high time complexity and will give TLE
    int recursiveSolve(vector<int>& coins, int amount ) {
        // base case
        if (amount == 0) {
            return 0;
        }
        // if amount is less than zero
        if (amount < 0) {
            return INT_MAX;
        }
        // store minimum number of coins
        int mini = INT_MAX;
        // Iterate through each coin in the 'coins' vector, recursively solve for remaining amount after subtracting the current coin
        for (int i = 0; i < coins.size(); i++) {
            int ans = recursiveSolve(coins, amount - coins[i]);
            if (ans != INT_MAX) {
                // if ans is non negative means ans is a valid value, then update 'mini' with the minimum number of coins needed to make up the 'amount'
                mini = min(mini, ans + 1);
            }
        }
        return mini;
    }

    // below is the code implementation of the problem using topDown approach of Dynamic Programming as the Time Complexity will be lower than recursive code
    // recursion + memoization
    int topDownSolveDP(vector<int>& coins, int amount, vector<int>& dp){
        // base case
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;
        }
        // step 3: check if answer already exists or not
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int ans = topDownSolveDP(coins, amount - coins[i], dp);
            if (ans != INT_MAX) {
                mini = min(mini, ans + 1);
            }
        }
        // step 2: replace answer with dp array
        dp[amount] = mini;
        return dp[amount];
    }

    // bottomUp (Tabulation Method) approach of Dynamic Programming
    // int bottomDownSolveDP
    
    int coinChange(vector<int>& coins, int amount) {
        // -------- Recursive Approach --------
        // int ansRecursive = recursiveSolve(coins, amount);
        // if (ansRecursive == INT_MAX)
        //     return -1;
        // else
        //     return ansRecursive;
    
        // -------- Dynamic Programming (Top Down Approach) --------
        // T.C ---> O(n), S.C ---> O(n + n) = O(n)
        // step 1: create dp array
        vector<int> dp(amount + 1, -1);
        int ansTopDown = topDownSolveDP(coins, amount, dp);
        if (ansTopDown == INT_MAX)
            return -1;
        else
            return ansTopDown;

        // -------- Dynamic Programming (Bottom Down Approach) --------
        // T.C ---> O(n), S.C ---> O(n)
        // int ansBottomUp = bottomDownSolveDP(n);
        // return ansBottomUp;
    }
};