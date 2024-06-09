class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        int sum = 0;
        int rem = 0;
        mp[rem]++;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            rem = sum % k;
            if (rem < 0) {
                rem = rem + k;
            }
            if (mp.find(rem) != mp.end()) {
                ans = ans + mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};