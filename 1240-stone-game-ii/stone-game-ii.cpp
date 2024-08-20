class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int length = piles.size();
        vector<vector<int>> dp(length + 1, vector<int>(length + 1, 0));

        vector<int> suffixSum(length + 1, 0);
        for (int i = length - 1; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        for (int i = 0; i <= length; i++) {
            dp[i][length] = suffixSum[i];
        }

        for (int index = length - 1; index >= 0; index--) {
            for (int maxTillNow = length - 1; maxTillNow >= 1; maxTillNow--) {
                for (int X = 1; X <= 2 * maxTillNow && index + X <= length;
                     X++) {
                    dp[index][maxTillNow] = max(
                        dp[index][maxTillNow],
                        suffixSum[index] - dp[index + X][max(maxTillNow, X)]);
                }
            }
        }
        return dp[0][1];
    }
};