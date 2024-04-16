class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int len = INT_MAX;
        while (end < nums.size()) {
            // include current number
            sum += nums[end];
            // now we have sum of current window
            while (sum >= target) {
                // minimize the window size and subtract excluded element, update length, move start forward
                len = min(len, end - start + 1);

                // subtract excluded element
                sum -= nums[start];

                // move start forward
                start++;

            }
            end++;
        }
        if (len == INT_MAX)
            return 0;
        else
            return len;
    }
};