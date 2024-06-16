class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // maxSum to store maximum sum that can be formed using the elements in
        // the array
        long maxSum = 0;
        // patch to keep track of the number of patches
        int patch = 0;
        int i = 0;

        while (maxSum < n) {
            if (i < nums.size() && nums[i] <= maxSum + 1) {
                // If the current element in the array is less than or equal to the maxSum,
                // we can extend the range of sums up to maxSum + nums[i]
                // and update maxSum and i accordingly 
                maxSum += nums[i];
                i++;
            } else {
                // If the current element in the array is greater than maxSum,
                // that means we have found a gap in our range of sums.
                // To fill this gap, we need to add maxSum + 1 in maxSum which
                // is and also  increment the patch count.
                maxSum += maxSum + 1;
                patch++;
            }
        }

        return patch;
    }
};