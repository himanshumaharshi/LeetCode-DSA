class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k < 0) {
            k += nums.size();
        }
        // reverse first size - k elements
        reverse(nums, 0, nums.size() - k - 1);
        // reverse the k elements
        reverse(nums, nums.size() - k, nums.size() - 1);
        // reverse whole array
        reverse(nums, 0, nums.size() - 1);
    }
};