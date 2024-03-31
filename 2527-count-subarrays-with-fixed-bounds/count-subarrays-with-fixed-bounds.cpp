class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n = size(nums);
        int st = -1, mini = -1, maxi = -1;
        for(int i = 0; i < n; i++){
            if (nums[i] < minK || nums[i] > maxK) {
                st=i;
            }
            if (nums[i] == minK) {
                mini=i;
            }
            if (nums[i] == maxK) {
                maxi=i;
            }
            int temp = min(mini, maxi) - st;
            ans += (temp < 0) ? 0 : temp;
        }
        return ans;
    }
};