class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0)
            return false;
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        sort(nums.begin(), nums.end());
        for (int num: nums) {
            if (freq[num] > 0) {
                for (int i = num + 1; i < num + k; i++) {
                    if (freq[i] == 0)
                        return false;
                    freq[i]--;
                }
                freq[num]--;
            }
        }
        return true;
    }
};