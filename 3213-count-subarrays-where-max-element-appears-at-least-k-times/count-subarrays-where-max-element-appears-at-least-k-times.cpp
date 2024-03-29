class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        int count = 0;
        long long ans = 0;
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            if (nums[j] == maxi)
                count++;
            while (i <= j && count >= k) {
                ans += (nums.size() - j);
                count -= (nums[i] == maxi);
                i++;
            }
            j++;
        }
        return ans;
    }
};