class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> ratio;

        // store the ratio of quality and wage in vector
        for (int i = 0; i < quality.size(); i++) {
            ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
        }

        // sort the vector based on ratio
        sort(ratio.begin(), ratio.end());

        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double maxRate = 0.0;

        for (int i = 0; i < k; i++) {
            qualitySum += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            maxHeap.push(quality[ratio[i].second]);
        }

        double minCost = maxRate * qualitySum;
        for (int i = k; i < quality.size(); i++) {
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= maxHeap.top();
            maxHeap.pop();

            qualitySum += quality[ratio[i].second];
            maxHeap.push(quality[ratio[i].second]);
            minCost = min(minCost, maxRate * qualitySum);
        }
        
        return minCost;
    }
};