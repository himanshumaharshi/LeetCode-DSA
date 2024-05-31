class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> mp;
        // store frequency of the elements
        for (auto ele: nums) {
            mp[ele]++;
        }

        vector<int> ans;
        for (auto ele: mp) {
            if (ele.second == 1)
                ans.push_back(ele.first);
        }
        return ans;
    }
};