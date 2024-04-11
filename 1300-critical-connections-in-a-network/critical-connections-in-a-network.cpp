class Solution {
public:
    void getCriticalConnections(int src, int parent, int& timer,
                                vector<int>& Tin, vector<int>& lowTime,
                                unordered_map<int, bool>& visited,
                                vector<vector<int>>& ans,
                                unordered_map<int, list<int>>& adjList) {
        visited[src] = true;
        Tin[src] = timer;
        lowTime[src] = timer;
        timer++;

        for (auto nbr : adjList[src]) {
            if (nbr == parent) {
                continue;
            }
            if (!visited[nbr]) {
                // dfs call
                getCriticalConnections(nbr, src, timer, Tin, lowTime, visited,
                                       ans, adjList);
                // update lowTime
                lowTime[src] = min(lowTime[src], lowTime[nbr]);
                // check for bridge
                if (lowTime[nbr] > Tin[src]) {
                    // store answer in ans array
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            } else {
                // node is visited and not a parent
                // update lowTime
                lowTime[src] = min(lowTime[src], lowTime[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // create a adjacency list and store graph
        unordered_map<int, list<int>> adjList;
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;
        int src = 0; // source node
        int parent = -1; // parent node
        int timer = 1;
        vector<int> Tin(n); // current insertion time
        vector<int> lowTime(n); // lowest insertion time
        unordered_map<int, bool> visited;

        getCriticalConnections(src, parent, timer, Tin, lowTime, visited, ans,
                               adjList);

        return ans;
    }
};