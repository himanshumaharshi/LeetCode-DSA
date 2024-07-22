class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> p;
        for (int i = 0; i < n; i++) {
            p.push_back({heights[i], names[i]});
        }
        auto lambda = [](pair<int, string>& P1, pair<int, string>& P2) {
            return P1.first > P2.first;
        };
        sort(p.begin(), p.end(), lambda);
        vector<string> ans;
        for (auto ele: p) {
            ans.push_back(ele.second);
        }
        return ans;
    }
};