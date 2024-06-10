class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the break point
        int idx = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        // if no breakpoint exist then reverse the array and return
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // find the greater element and swap with idx element
        for (int i = nums.size() - 1; i >= idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }
        // now at last reverse the remaining array
        reverse(nums.begin() + idx + 1, nums.end());
    }
};