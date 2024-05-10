class Solution {
public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return (double)(a.first) / a.second < (double)(b.first) / b.second;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> data;
        int n = arr.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                data.push_back({arr[i], arr[j]});
        sort(data.begin(), data.end(), comp);
        return {data[k - 1].first, data[k - 1].second};
    }
};