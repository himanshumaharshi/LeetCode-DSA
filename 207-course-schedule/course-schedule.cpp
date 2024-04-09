class Solution {
public:
    bool topologicalSortBFS(int n, unordered_map<int, list<int>>& adjList) {
        vector<int> ans;
        queue<int> q;
        unordered_map<int, int> indegree;

        for (auto i : adjList) {
            int src = i.first;
            for (auto nbr : i.second) {
                indegree[nbr]++;
            }
        }
        // put all nodes inside queue, which has indegre = 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // bfs logic
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                // check for zero indegree again
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        if (ans.size() == n) { // valid topolgical sort
            return true;
        } else { // invalid topological sort
            return false;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adjList;

        // build adjacency list
        for (auto task : prerequisites) {
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }
        bool ans = topologicalSortBFS(numCourses, adjList);
        return ans;
    }
};