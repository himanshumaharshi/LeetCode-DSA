class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(prefix);
            prefix *= nums[i];
        }
        // for input 1, 2, 3, 4
        // after above for loop ans array will contain --> 1, 1, 2, 6
        int suffix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        // after this for loop ans array will contail --> 24, 12, 8, 6
        return ans;
    }
};