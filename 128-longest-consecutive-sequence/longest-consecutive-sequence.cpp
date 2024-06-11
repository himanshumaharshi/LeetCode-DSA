class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int longest = 1;
        sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        for (auto ele: st) {
            //if 'ele' is a starting number
            if (st.find(ele - 1) == st.end()) {
                //find consecutive numbers
                int count = 1;
                int x = ele;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    count = count + 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};