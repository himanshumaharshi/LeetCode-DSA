class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // declare array count with size nums + 1
        int count[nums.size() + 1];
        // initialize all the elements of the count array with 0
        memset(count, 0, sizeof count);
        count[0] = 1;
        int ans = 0;
        int sum = 0;
        // Iterate over elements in 'nums', updating running sum 'sum', counting occurrences of sums meeting 'goal' condition in 'count', and updating 'ans' accordingly.
        for (int& v : nums) {
            sum += v;
            if (sum - goal >= 0) {
                ans += count[sum - goal];
            }
            ++count[sum];
        }
        return ans;
    }
};