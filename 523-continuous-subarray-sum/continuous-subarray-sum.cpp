class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixMod = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            prefixMod = (prefixMod + nums[i]) % k;
            if (mp.find(prefixMod) != mp.end()) {
                // ensures that the size of subarray is atleast 2
                if (i - mp[prefixMod] > 1) {
                    return true;
                }
            } else {
                // mark the value of prefixMod with the current index.
                mp[prefixMod] = i;
            }
        }
        return false;
    }
};