class Solution {
public:
    /* ------------------------- Brute Force -------------------------
    // T.C -> O(V * (V + E)) = O(V^2 + E) = O(N)
    // S.C -> O(N)
    void dfs(unordered_map<int, vector<int>>&adjacencyList, vector<vector<int>>& ans, int ancestor, int currNode) {
        // Traverse neighbors of the current node
        for (auto &neighbour: adjacencyList[currNode]) {
            // If the ancestor list for the neighbor is empty or doesn't contain the ancestor
            if (ans[neighbour].empty() || ans[neighbour].back() != ancestor) {
                ans[neighbour].push_back(ancestor);
                // Recursively perform DFS for the neighbor
                dfs(adjacencyList, ans, ancestor, neighbour);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        // Adjacency list representation of the graph
        unordered_map<int, vector<int>> adjacencyList;
        // Build the adjacency list from the edges
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adjacencyList[u].push_back(v); // u -> v
        }
        // Perform DFS for each node to find its ancestors
        for (int i = 0; i < n; i++) {
            int ancestor = i;
            dfs(adjacencyList, ans, ancestor, i);
        }
        return ans;
    }*/


    // ------------------------- Optimal -------------------------
    void dfs(unordered_map<int, vector<int>>& adjList, vector<bool>& visited, int i) {
        visited[i] = true;
        // Traverse all neighbors of the current node
        for (int &ele: adjList[i]) {
            // make next call only if node is not visited
            if (visited[ele] != true) {
                dfs(adjList, visited, ele);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        // Adjacency list representation of the reverse graph
        unordered_map<int, vector<int>> adjList;
        // Build the adjacency list from the edges (make graph reverse)
        for (auto& vec: edges) {
            int u = vec[0];
            int v = vec[1];
            adjList[v].push_back(u); // v -> u
        }
        // Perform DFS for each node to find its ancestors
        for (int i = 0; i < n; i++) {
            vector<int> ancestors;
            vector<bool> visited(n, false);
            dfs(adjList, visited, i);
            // Collect all nodes that are ancestors of node i
            for (int j = 0; j < n; j++) {
                if (j == i) 
                    continue;
                if (visited[j] == true) {
                    ancestors.push_back(j);
                }
            }
            ans.push_back(ancestors);
        }
        return ans;
    }
};