class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int remainder = numBottles % numExchange;
            numBottles = numBottles / numExchange;
            ans += numBottles;
            numBottles += remainder;
        }
        return ans;

        // return numBottles + (numBottles-1) / (numExchange-1); // Optimal Approach (Using maths) T.C : O(1) S.C : O(1)
    }
};