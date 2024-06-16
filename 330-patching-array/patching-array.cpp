class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxreach = 0;
        int patch = 0;
        int i = 0;

        while (maxreach < n) {
            if (i < nums.size() &&
                nums[i] <= maxreach + 1) // this is for if do not patch
            {
                maxreach += nums[i];
                i++;
            } else // this for patch
            {
                maxreach += (maxreach + 1);
                patch++;
            }
        }

        return patch;
    }
};