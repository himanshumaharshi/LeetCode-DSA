class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            int freq = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    freq++;
                }
            }
            if (freq > n) {
                return nums[i];
            }
        }
        return 0;
    }
};