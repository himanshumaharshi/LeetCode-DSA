class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {  // T.C = O(E + N log N), S.C -> O(N)
        long long importance = 0;
        // Get the degree (number of connections) of all the nodes
        vector<int> degree(n, 0); // S.c -> O(n)
        for (auto edge: roads) { // T.C -> O(number of edges)
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        // Sort the degrees in ascending order
        sort(degree.begin(), degree.end()); // T.C -> O(N log N)
        long long value = 1;
        for (int i = 0; i < degree.size(); i++) { // T.C -> O(N)
            // Calculate the total importance by multiplying each degree by an incrementing value and summing up
            importance += (degree[i] * value++);
        }
        return importance;
    }
};