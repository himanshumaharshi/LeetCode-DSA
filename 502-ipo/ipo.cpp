class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size(), i = 0;

        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++)
            projects[i] = {capital[i], profits[i]};

        sort(projects.begin(), projects.end());
        priority_queue<int> maximizeCapital;

        while (k--) {
            while (i < n && projects[i].first <= w) {
                maximizeCapital.push(projects[i++].second);
            }
            if (maximizeCapital.empty())
                break;
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        
        return w;
    }
};