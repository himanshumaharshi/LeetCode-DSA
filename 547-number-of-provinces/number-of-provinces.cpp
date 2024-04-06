class Solution {
public:
    void getProvincesUsingDFS(unordered_map<int, bool>& visited, int src, vector<vector<int>>& isConnected) {
        // mark current source visited
        visited[src] = true;
        // row -> src, col -> we will write loop
        int size = isConnected[src].size();
        for (int col = 0; col < size; col++) {
            if (isConnected[src][col] == 1) {
                if (!visited[col]) {
                    getProvincesUsingDFS(visited, col, isConnected);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, bool> visited;
        int count = 0;
        int n = isConnected.size();
        // i represents nodes here
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                getProvincesUsingDFS(visited, i, isConnected);
                count++;
            }
        }
        return count;
    }
};